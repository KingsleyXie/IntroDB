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

Route::get('/', function () {
    return view('welcome');
});

Route::get('/init', 'InitializeDB@index');

Route::post('/sell', 'SalesController@sell');
Route::post('/return', 'SalesController@return');
Route::get('/limits', 'SalesController@limits');

Route::get('/inventory/all', 'InventoryController@index');
Route::post('/inventory/add', 'InventoryController@add');
Route::post('/inventory/update/{id}', 'InventoryController@update');

Route::get('/staff/all', 'StaffController@index');
Route::post('/staff/add', 'StaffController@add');
Route::post('/staff/update/{id}', 'StaffController@update');

Route::get('/finance/all', 'FinanceController@index');
Route::post('/finance/add', 'FinanceController@add');

Route::get('/report/finance', 'ReportController@finance');
Route::get('/report/supplier', 'ReportController@supplier');
Route::get('/report/customer', 'ReportController@customer');
