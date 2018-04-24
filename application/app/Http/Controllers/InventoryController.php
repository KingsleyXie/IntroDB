<?php

namespace App\Http\Controllers\System;

use App\Db;

use App\Http\Controllers\Controller;
use Illuminate\Http\Request;

class InventoryController extends Controller
{
    public function index()
    {
        $model = new Db;

        return response()->json([
            'code' => 0,
            'data' => $model->select("inventory")
        ]);
    }
}
