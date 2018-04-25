<?php

namespace App\Http\Controllers;

use App\Db;

use App\Http\Controllers\Controller;
use Illuminate\Http\Request;

class ReportController extends Controller
{
    public function finance()
    {
        $db = new Db;

        return response()->json([
            'code' => 0,
            'data' => $db->select("finance")
        ]);
    }

    public function supplier()
    {
        $db = new Db;

        return response()->json([
            'code' => 0,
            'data' => $db->select("supplier")
        ]);
    }

    public function customer()
    {
        $db = new Db;

        return response()->json([
            'code' => 0,
            'data' => $db->select("customer")
        ]);
    }
}
