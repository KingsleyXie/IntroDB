<?php
namespace App\Http\Controllers;;

use App\Db;

use App\Http\Controllers\Controller;
use Illuminate\Http\Request;

class InitializeDB extends Controller
{
	public function index()
	{
		$file = fopen(config('db.file'), 'w');
		fwrite($file, config('db.init.db'));
		fclose($file);

		$this->insert('customers', config('db.init.customers'));
		$this->insert('finance', config('db.init.finance'));
		$this->insert('items', config('db.init.items'));
		$this->insert('staffs', config('db.init.staffs'));
		$this->insert('suppliers', config('db.init.suppliers'));

		return response()->json([
			'code' => 0,
			'data' => '数据库初始化成功！'
		]);
	}

	private function insert($table, $data)
	{
		$db = new Db;
		$db->addTable($table);

		$data = json_decode($data);
		foreach ($data as $row) {
			$db->insert($table, $row);
		}
	}
}
