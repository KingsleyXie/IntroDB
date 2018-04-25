<?php

namespace App\Http\Controllers;

use App\Db;

use App\Http\Controllers\Controller;
use Illuminate\Http\Request;

class InventoryController extends Controller
{
    public function index()
    {
        $db = new Db;

        return response()->json([
            'code' => 0,
            'data' => $db->select("inventory")
        ]);
    }

    public function add(Request $request)
    {
        $db = new Db;

        $data = [
            "barcode" => $request->barcode,
            "brand" => $request->brand,
            "name" => $request->name,
            "type" => $request->type,
            "unspsc" => $request->unspsc,
            "price" => $request->price,
            "salePrice" => $request->salePrice,
            "inventoryQuantity" => $request->inventoryQuantity,
            "threshold" => $request->threshold,
            "expiredTime" => $request->expiredTime,
            "importTime" => $request->time,
            "updateTime" => $request->time
        ];

        $db->insert("inventory", $data);

        $amount = floatval($request->inventoryQuantity);
        $price = floatval($request->price);

        $db->insert("finance", [
            "name" => "Inventory Add Record",
            "income" => 0,
            "expenditure" => $amount * $price,
            "date" => [
                "year" => date('Y'),
                "month" => date('m'),
                "day" => date('d')
            ]
        ]);

        $suppliers = $db->select("supplier");
        $supplier = $suppliers[$request->supplierID];

        array_push($supplier["transactions"], [
            "transactionTime" => $request->time,
            "itemID" => $db->getCount("inventory"),
            "itemName" => $request->name,
            "itemAmount" => $request->inventoryQuantity,
            "itemPrice" => $request->price,
        ]);

        $db->update("supplier", $request->supplierID, $supplier);

        return response()->json([
            'code' => 0
        ]);
    }

    public function update(Request $request, $id)
    {
        $db = new Db;

        $items = $db->select("inventory");
        $item = $items[$id];

        $item["brand"] = $request->brand;
        $item["name"] = $request->name;
        $item["type"] = $request->type;
        $item["unspsc"] = $request->unspsc;
        $item["price"] = $request->price;
        $item["salePrice"] = $request->salePrice;
        $item["inventoryQuantity"] = $request->inventoryQuantity;
        $item["threshold"] = $request->threshold;
        $item["expiredTime"] = $request->expiredTime;
        $item["updateTime"] = $request->time;

        $db->update("inventory", $id, $item);

        $amount = floatval($request->inventoryQuantity);
        $price = floatval($request->price);

        $db->insert("finance", [
            "name" => "Inventory Add Record",
            "income" => 0,
            "expenditure" => $amount * $price,
            "date" => [
                "year" => date('Y'),
                "month" => date('m'),
                "day" => date('d')
            ]
        ]);

        $suppliers = $db->select("supplier");
        $supplier = $suppliers[$request->supplierID];

        array_push($supplier["transactions"], [
            "transactionTime" => $request->time,
            "itemID" => $db->getCount("inventory"),
            "itemName" => $request->name,
            "itemAmount" => $request->inventoryQuantity,
            "itemPrice" => $request->price,
        ]);

        $db->update("supplier", $request->supplierID, $supplier);

        return response()->json([
            'code' => 0
        ]);
    }
}
