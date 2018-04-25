<?php

namespace App\Http\Controllers;

use App\Db;

use App\Http\Controllers\Controller;
use Illuminate\Http\Request;

class FinanceController extends Controller
{
    public function index()
    {
        $db = new Db;

        return response()->json([
            'code' => 0,
            'data' => $db->select("finance")
        ]);
    }

    public function add(Request $request)
    {
        $db = new Db;
        $db->insert("finance", [
            "name" => $request->financeName,
            "income" => $request->income,
            "expenditure" => $request->expenditure,
            "date" => [
                "year" => date('Y'),
                "month" => date('m'),
                "day" => date('d')
            ]
        ]);

        return response()->json([
            'code' => 0
        ]);
    }
}
