<?php

// namespace App\System;

// include 'Db.php';

class InventoryModeld
{
	public function index()
	{
		echo $this->select("inventory");
	}
	/*
	int display()
	{
		response = record["items"];
		cout << response;
		return 0;
	}

	int add()
	{
		record["items"].push_back(
		{
			{"barcode", request["barcode"]},
			{"brand", request["brand"]},
			{"name", request["name"]},
			{"type", request["type"]},
			{"unspsc", request["unspsc"]},
			{"price", request["price"]},
			{"salePrice", request["salePrice"]},
			{"inventoryQuantity", request["inventoryQuantity"]},
			{"threshold", request["threshold"]},
			{"expiredTime", request["expiredTime"]},
			{"importTime", request["time"]},
			{"updateTime", request["time"]}
		});

		double amount = request["inventoryQuantity"], price = request["price"];
		record["finance"].push_back(
		{
			{"name", "Inventory Add Record"},
			{"income", 0},
			{"expenditure", amount * price},
			{"date", 
				{
					{"year", request["year"]},
					{"month", request["month"]},
					{"day", request["day"]}
				}
			}
		});

		data_index = request["supplierID"];
		int itemID = record["items"].size();
		record["suppliers"][data_index]["transactions"].push_back(
		{
			{"transactionTime", request["time"]},
			{"itemID", itemID},
			{"itemName", request["name"]},
			{"itemAmount", request["inventoryQuantity"]},
			{"itemPrice", request["price"]}
		});

		response ={{"code", 0}};
		cout << response;
		return 0;
	}

	int update()
	{
		data_index = request["itemID"];
		record["items"][data_index] =
		{
			{"barcode", record["items"][data_index]["barcode"]},
			{"brand", request["brand"]},
			{"name", request["name"]},
			{"type", request["type"]},
			{"unspsc", request["unspsc"]},
			{"price", request["price"]},
			{"salePrice", request["salePrice"]},
			{"inventoryQuantity", request["inventoryQuantity"]},
			{"threshold", request["threshold"]},
			{"expiredTime", request["expiredTime"]},
			{"importTime", record["items"][data_index]["importTime"]},
			{"updateTime", request["time"]}
		};

		double amount = request["inventoryQuantity"], price = request["price"];
		record["finance"].push_back(
		{
			{"name", "Inventory Update Record"},
			{"income", 0},
			{"expenditure", amount * price},
			{"date", 
				{
					{"year", request["year"]},
					{"month", request["month"]},
					{"day", request["day"]}
				}
			}
		});

		data_index = request["supplierID"];
		record["suppliers"][data_index]["transactions"].push_back(
		{
			{"transactionTime", request["time"]},
			{"itemID", request["itemID"]},
			{"itemName", request["name"]},
			{"itemAmount", request["inventoryQuantity"]},
			{"itemPrice", request["price"]}
		});

		response ={{"code", 0}};
		cout << response;
		return 0;
	}
*/}
// $a = new InventoryModel;
// $a->index();