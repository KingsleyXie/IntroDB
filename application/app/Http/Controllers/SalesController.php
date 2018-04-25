<?php

namespace App\Http\Controllers;

use App\Db;

use App\Http\Controllers\Controller;
use Illuminate\Http\Request;

class SalesController extends Controller
{
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

    public function sell()
    {
    }

    public function return()
    {
    }
}
