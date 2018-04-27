<?php
namespace App\Http\Controllers;;

use App\Db;

use App\Http\Controllers\Controller;
use Illuminate\Http\Request;

class DBController extends Controller
{
	private function add($table, $data)
	{
		$db = new Db;
		$db->addTable($table);

		$data = json_decode($data);
		foreach ($data as $row) {
			$db->insert($table, $row);
		}
	}

	public function init()
	{
		$file = fopen(config('db.file'), 'w');
		fwrite($file, config('db.empty'));
		fclose($file);

		$this->add('customer', config('data.init.customer'));
		$this->add('finance', config('data.init.finance'));
		$this->add('inventory', config('data.init.inventory'));
		$this->add('staff', config('data.init.staff'));
		$this->add('supplier', config('data.init.supplier'));

		return view('db', ['info' => '数据库初始化成功！']);
	}

	public function sample()
	{
		$file = fopen(config('db.file'), 'w');
		fwrite($file, config('db.empty'));
		fclose($file);

		$this->add('customer', config('data.sample.customer'));
		$this->add('inventory', config('data.sample.inventory'));
		$this->add('staff', config('data.sample.staff'));
		$this->add('supplier', config('data.sample.supplier'));

		$data = [];
		$finance = json_decode(config('data.sample.finance'), true);
		foreach ($finance as $row) {
			$row['date']['year'] = date('Y');
			$row['date']['month'] = date('m');
			$day = date('d');

			switch ($row['date']['day']) {
				case $day:
					break;

				case 0:
					$row['date']['day'] = $day;
					array_push($data, $row);
					break;

				default:
					array_push($data, $row);
					break;
			}
		}

		$this->add('finance', json_encode($data));

		return view('db', ['info' => '样例数据生成成功！']);
	}
}
