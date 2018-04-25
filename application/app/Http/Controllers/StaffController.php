<?php

namespace App\Http\Controllers;

use App\Db;

use App\Http\Controllers\Controller;
use Illuminate\Http\Request;

class StaffController extends Controller
{
    public function index()
    {
        $db = new Db;

        return response()->json([
            'code' => 0,
            'data' => $db->select("staff")
        ]);
    }

    public function add(Request $request)
    {
        $db = new Db;
        $db->insert(
            "staff",
            $request->all()
        );

        return response()->json([
            'code' => 0
        ]);
    }

    public function update(Request $request, $id)
    {
        $db = new Db;
        $db->update(
            "staff",
            $id, $request->all()
        );

        return response()->json([
            'code' => 0
        ]);
    }
}
