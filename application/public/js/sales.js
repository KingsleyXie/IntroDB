$("#loading").hide();
limitSet();

$("#sell").submit(function(e) {
	e.preventDefault();

	var url = 'sell/customer/' +
	$("#sell [name=customerID]").val() +
	'/inventory/' + $("#sell [name=itemID]").val();

	$.get(url, function(response) {
			if (response.code == 0) {
				Materialize.toast('购物记录添加成功！', 2000);
				limitSet();
				setTimeout(function () {
					$("#sell").modal('close');
				}, 1700);
			}
		}
	)

	.fail(function() {
		Materialize.toast('操作失败', 3000);
	});
});

$("#return").submit(function(e) {
	e.preventDefault();

	var url = 'return/customer/' +
	$("#return [name=customerID]").val() +
	'/inventory/' + $("#sell [name=itemID]").val();

	$.get(url, function(response) {
			if (response.code == 0) {
				Materialize.toast('退货记录添加成功！', 2000);
				limitSet();
				window.setTimeout(function () {
					$("#return").modal('close');
				}, 1700);
			}
		}
	)

	.fail(function() {
		Materialize.toast('操作失败', 3000);
	});
});

function limitSet() {
	$.get('limits', function(response) {
			$('[name="itemID"]').attr("max", response.data.items - 1)
			$('[name="customerID"]').attr("max", response.data.customers - 1)
		}
	);
}
