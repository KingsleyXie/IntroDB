<?php

namespace App\Http\Controllers;

use App\Http\Controllers\Controller;
use Illuminate\Http\Request;

class APIController extends Controller
{
    public function index(Request $request)
    {
        $auth = array('http' =>
            array('header' => "Authorization:APPCODE YOUR_APPCODE_HERE")
            // Add your APPCODE here, you can get it on
            // https://market.aliyun.com/products/56928004/cmapi011806.html
        );
        $context = stream_context_create($auth);

        $base_url = 'http://jisutxmcx.market.alicloudapi.com/barcode2/query?barcode=';

        $result = file_get_contents(
            $base_url . $request->barcode, false, $context
        );

        return response($result);
    }
}
