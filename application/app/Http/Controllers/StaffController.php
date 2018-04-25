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
        $db->insert("staff", [
            "jobNo" => $request->jobNo,
            "name" => $request->name,
            "gender" => $request->gender,
            "nation" => $request->nation,
            "nativePlace" => $request->nativePlace,
            "department" => $request->department,
            "postion" => $request->postion,
            "birthday" => $request->birthday,
            "contact" => $request->contact,
            "address" => $request->address,
            "salary" => $request->salary,
            "entryTime" => $request->entryTime,
            "status" => $request->status
        ]);

        return response()->json([
            'code' => 0
        ]);
    }

    public function update(Request $request, $id)
    {
        $db = new Db;
        $db->update("staff", $id, [
            "jobNo" => $request->jobNo,
            "name" => $request->name,
            "gender" => $request->gender,
            "nation" => $request->nation,
            "nativePlace" => $request->nativePlace,
            "department" => $request->department,
            "postion" => $request->postion,
            "birthday" => $request->birthday,
            "contact" => $request->contact,
            "address" => $request->address,
            "salary" => $request->salary,
            "entryTime" => $request->entryTime,
            "status" => $request->status
        ]);

        return response()->json([
            'code' => 0
        ]);
    }
}
