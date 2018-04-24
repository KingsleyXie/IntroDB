<?php

namespace App\Http\Controllers\System;

use App\Http\Controllers\Controller;
use App\System\SalesModel;

use Illuminate\Http\Request;

class SalesController extends Controller
{
    public function sellItem(Request $request)
    {
        $model = new SalesModel;
        $model->sellItem(
            $request->customerID,
            $request->itemID,
            $request->time,
            $request->year,
            $request->month,
            $request->day
        );

        return response()->json([
            'code' => 0
        ]);
    }
}
