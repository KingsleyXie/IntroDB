<?php

namespace App\Http\Controllers;

use App\Db;

use App\Http\Controllers\Controller;
use Illuminate\Http\Request;

class SalesController extends Controller
{
    public function sell(Request $request, $customer, $inventory)
    {
        $db = new Db;

        $customers = $db->select("customer");
        $items = $db->select("inventory");

        if (!(array_key_exists($customer, $customers)
            && array_key_exists($inventory, $items))) {
            return response()->json([
                'code' => 1,
                'data' => '请求数据有误！'
            ]);
        }

        $cust = $customers[$customer];
        $item = $items[$inventory];

        $item["inventoryQuantity"] = $item["inventoryQuantity"] - 1;
        $db->update("inventory", $inventory, $item);

        $payment = $item["salePrice"];
        $points = $payment * 1.5;

        $finance = [
            "name" => "Sell Record",
            "income" => $payment,
            "expenditure" => 0,
            "date" => [
                "year" => date('Y'),
                "month" => date('m'),
                "day" => date('d')
            ]
        ];

        array_push($cust["purchases"], [
            "purchaseTime" => date('Y-m-d'),
            "payment" => $payment,
            "points" => $points
        ]);

        $cust["totalPoints"] = $cust["totalPoints"] + $points;

        $db->update("customer", $customer, $cust);

        return response()->json([
            'code' => 0
        ]);
    }

    public function limits()
    {
        $db = new Db;

        return response()->json([
            'code' => 0,
            'data' => [
                'items' => $db->getCount("inventory"),
                'suppliers' => $db->getCount("supplier"),
                'customers' => $db->getCount("customer")
            ]
        ]);
    }
}
