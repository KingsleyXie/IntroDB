$(document).ready(function() {
	display();

	$("#finance").submit(function(e) {
		e.preventDefault();

		var data = {};
		$(this).serializeArray().map(function(x) {
			data[x.name] = x.value;
		});
		data["income"] = parseFloat(data["income"]);
		data["expenditure"] = parseFloat(data["expenditure"]);

		$.post(
			'finance/add', data,
			function(response) {
				if (response.code == 0) {
					Materialize.toast('财务流水添加成功！', 1700);
					setTimeout(function () {
						$("#finance").modal('close');
						display();
					}, 2000);
				}
			}
		)

		.fail(function() {
			Materialize.toast('财务流水添加出错', 3000);
		});
	});
});

function display() {
	$.get(
		'finance/all',
		function(response) {
			$("#display").html('');
			$.each(response.data, function(i, finance) {
				$("#display").append(
				'<tr>' +
					'<td>' + finance.id + '</td>' +
					'<td>' + finance.name + '</td>' +
					'<td>' + finance.income + '</td>' +
					'<td>' + finance.expenditure + '</td>' +
					'<td>' + finance.date.year + '</td>' +
					'<td>' + finance.date.month + '</td>' +
					'<td>' + finance.date.day + '</td>' +
				'</tr>');
			});
		}
	)

	.fail(function() {
		Materialize.toast('获取数据出错', 3000);
	});
	
	$("#loading").hide();
}
