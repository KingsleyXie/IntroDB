function suppliers() {
	$.get(
		'report/supplier',
		function(response) {
			$("#display").hide(600);
			setTimeout(function () {
				$("#display").html('');
				$.each(response.data, function(i, supplier) {
					$("#display").append(
					'<div class="card">' +
						'<div class="card-content" id="table' + supplier.id + '">' +
							'<table class="highlight">' +
								'<thead>' +
									'<tr>' +
										'<th>序号</th>' +
										'<th>供货商名称</th>' +
									'</tr>' +
								'</thead>' +
								'<tbody>' +
									'<tr>' +
										'<td>' + supplier.id + '</td>' +
										'<td>' + supplier.supplierName + '</td>' +
									'</tr>' +
								'</tbody>' +
							'</table>' +
						'</div>' +
					'</div>');

					if (supplier.transactions.length) {
						$("#table" + supplier.id).append(
						'<div class="card-content subtable">' +
							'<table class="highlight responsive-table">' +
								'<thead>' +
									'<tr>' +
										'<th>交易时间</th>' +
										'<th>商品ID</th>' +
										'<th>商品名称</th>' +
										'<th>商品数量</th>' +
										'<th>商品单价</th>' +
									'</tr>' +
								'</thead>' +
								'<tbody id="subtable' + supplier.id + '"></tbody>' +
							'</table>' +
						'</div>');
					}

					$.each(supplier.transactions, function(t, transaction) {
						$("#subtable" + supplier.id).append(
						'<tr>' +
							'<td>' + transaction.transactionTime + '</td>' +
							'<td>' + transaction.itemID + '</td>' +
							'<td>' + transaction.itemName + '</td>' +
							'<td>' + transaction.itemAmount + '</td>' +
							'<td>' + transaction.itemPrice + '</td>' +
						'</tr>');
					});
				});
			}, 600);
			$("#display").show(700);
		}
	)

	.fail(function() {
		Materialize.toast('获取数据出错', 3000);
	});

	$("#loading").hide();
}

function customers() {
	$.get(
		'report/customer',
		function(response) {
			$("#display").hide(600);
			setTimeout(function () {
				$("#display").html('');
				$.each(response.data, function(i, customer) {
					$("#display").append(
					'<div class="card">' +
						'<div class="card-content" id="table' + customer.id + '">' +
							'<table class="highlight">' +
								'<thead>' +
									'<tr>' +
										'<th>序号</th>' +
										'<th>客户名称</th>' +
										'<th>会员卡号</th>' +
										'<th>当前积分</th>' +
									'</tr>' +
								'</thead>' +
								'<tbody>' +
									'<tr>' +
										'<td>' + customer.id + '</td>' +
										'<td>' + customer.customerName + '</td>' +
										'<td>' + customer.customerNo + '</td>' +
										'<td>' + customer.totalPoints + '</td>' +
									'</tr>' +
								'</tbody>' +
							'</table>' +
						'</div>' +
					'</div>');

					if (customer.purchases.length) {
						$("#table" + customer.id).append(
						'<div class="card-content subtable">' +
							'<table class="highlight responsive-table">' +
								'<thead>' +
									'<tr>' +
										'<th>购物时间</th>' +
										'<th>付款</th>' +
										'<th>积分</th>' +
									'</tr>' +
								'</thead>' +
								'<tbody id="subtable' + customer.id + '"></tbody>' +
							'</table>' +
						'</div>');
					}

					$.each(customer.purchases, function(t, purchase) {
						$("#subtable" + customer.id).append(
						'<tr>' +
							'<td>' + purchase.purchaseTime + '</td>' +
							'<td>' + purchase.payment + '</td>' +
							'<td>' + purchase.points + '</td>' +
						'</tr>');
					});
				});
			}, 600);
			$("#display").show(700);
		}
	)

	.fail(function() {
		Materialize.toast('获取数据出错', 3000);
	});

	$("#loading").hide();
}
