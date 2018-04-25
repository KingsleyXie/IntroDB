<?php

return [
	'name' => 'db',
	'path' => '../app/db/',
	'file' => '../app/db/db.json',
	'exepath' => '../app/db/app.exe',
	'run' => 'cd ../app/db/ && app.exe ',
	'compile' => 'g++ -std=c++11 -o ../app/db/app.exe ../app/db/app.cpp',
	'init' => [
		'db' => '{"name":"db","tables":[]}',
		'finance' => '[]',
		'inventory' => '[]',
		'staff' => '[]',
		'customer' => '[{"customerName":"Customer0","customerNo":20170900,"totalPoints":0,"purchases":[]},{"customerName":"Customer1","customerNo":20170901,"totalPoints":0,"purchases":[]},{"customerName":"Customer2","customerNo":20170902,"totalPoints":0,"purchases":[]},{"customerName":"Customer3","customerNo":20170903,"totalPoints":0,"purchases":[]},{"customerName":"Customer4","customerNo":20170904,"totalPoints":0,"purchases":[]},{"customerName":"Customer5","customerNo":20170905,"totalPoints":0,"purchases":[]},{"customerName":"Customer6","customerNo":20170906,"totalPoints":0,"purchases":[]},{"customerName":"Customer7","customerNo":20170907,"totalPoints":0,"purchases":[]},{"customerName":"Customer8","customerNo":20170908,"totalPoints":0,"purchases":[]},{"customerName":"Customer9","customerNo":20170909,"totalPoints":0,"purchases":[]},{"customerName":"Customer10","customerNo":20170910,"totalPoints":0,"purchases":[]},{"customerName":"Customer11","customerNo":20170911,"totalPoints":0,"purchases":[]},{"customerName":"Customer12","customerNo":20170912,"totalPoints":0,"purchases":[]},{"customerName":"Customer13","customerNo":20170913,"totalPoints":0,"purchases":[]},{"customerName":"Customer14","customerNo":20170914,"totalPoints":0,"purchases":[]},{"customerName":"Customer15","customerNo":20170915,"totalPoints":0,"purchases":[]},{"customerName":"Customer16","customerNo":20170916,"totalPoints":0,"purchases":[]},{"customerName":"Customer17","customerNo":20170917,"totalPoints":0,"purchases":[]}]',
		'supplier' => '[{"supplierName":"Supplier0","transactions":[]},{"supplierName":"Supplier1","transactions":[]},{"supplierName":"Supplier2","transactions":[]},{"supplierName":"Supplier3","transactions":[]},{"supplierName":"Supplier4","transactions":[]},{"supplierName":"Supplier5","transactions":[]},{"supplierName":"Supplier6","transactions":[]},{"supplierName":"Supplier7","transactions":[]},{"supplierName":"Supplier8","transactions":[]},{"supplierName":"Supplier9","transactions":[]},{"supplierName":"Supplier10","transactions":[]},{"supplierName":"Supplier11","transactions":[]},{"supplierName":"Supplier12","transactions":[]},{"supplierName":"Supplier13","transactions":[]},{"supplierName":"Supplier14","transactions":[]},{"supplierName":"Supplier15","transactions":[]},{"supplierName":"Supplier16","transactions":[]},{"supplierName":"Supplier17","transactions":[]}]'
	]
];
