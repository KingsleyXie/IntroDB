<?php

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/



/************ Resources ************/
Route::get('/', function() {
	return \File::get(public_path() . '/html/index.html');
});
Route::get('/clients', function() {
	return \File::get(public_path() . '/html/clients.html');
});
Route::get('/finance', function() {
	return \File::get(public_path() . '/html/finance.html');
});
Route::get('/inventory', function() {
	return \File::get(public_path() . '/html/inventory.html');
});
Route::get('/report', function() {
	return \File::get(public_path() . '/html/report.html');
});
Route::get('/sales', function() {
	return \File::get(public_path() . '/html/sales.html');
});
Route::get('/staffs', function() {
	return \File::get(public_path() . '/html/staffs.html');
});





/************ Interfaces ************/

// Database Initialization
Route::get(
	'/init',
	'InitializeDB@index'
);

// Sales Input Limits
Route::get(
	'/limits',
	'SalesController@limits'
);

// Sell & Return
Route::get(
	'/sell/customer/{customer}/inventory/{inventory}',
	'SalesController@sell'
);
Route::get(
	'/return/customer/{customer}/inventory/{inventory}',
	'SalesController@return'
);

// Inventory select, insert & update
Route::get(
	'/inventory/all',
	'InventoryController@index'
);
Route::post(
	'/inventory/add',
	'InventoryController@add'
);
Route::post(
	'/inventory/update/{id}',
	'InventoryController@update'
);

// Staff select, insert & update
Route::get(
	'/staff/all',
	'StaffController@index'
);
Route::post(
	'/staff/add',
	'StaffController@add'
);
Route::post(
	'/staff/update/{id}',
	'StaffController@update'
);

// Finance select & insert
Route::get(
	'/finance/all',
	'FinanceController@index'
);
Route::post(
	'/finance/add',
	'FinanceController@add'
);

// Report select
Route::get(
	'/report/finance',
	'ReportController@finance'
);
Route::get(
	'/report/supplier',
	'ReportController@supplier'
);
Route::get(
	'/report/customer',
	'ReportController@customer'
);
