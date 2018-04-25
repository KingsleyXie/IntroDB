var modifyingInv = false, modifyingStaff = false;

$(".modal").modal();
$("select").material_select();
$(".button-collapse").sideNav();

$(".datepicker").pickadate({
	selectMonths: true,
	selectYears: 15,
	format: 'yyyy-mm-dd'
});

$('[type="number"]').attr({ "min": "0" });
