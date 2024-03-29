<?php

namespace App;

class Db
{
	function __construct()
	{
		if (!file_exists(config('db.exepath')))
			shell_exec(config('db.compile'));
	}

	private function db_execute($operation)
	{
		$operation = str_replace(
			'"', '\"', json_encode($operation)
		);

		// Append "2>&1" to get stderr together
		$operation = '"' . $operation . '"';

		$cmd = config('db.run') . $operation;
		$result = shell_exec($cmd);

		return $result;

		/*
		Another way to get stdin and stderr together:


		$cmd = "app.exe \"$operation\"";

		$process = proc_open($cmd, [
			0 => ['pipe', 'r'],
			1 => ['pipe', 'w'],
			2 => ['pipe', 'w']
		], $pipes);

		if (is_resource($process)) {
			$out = stream_get_contents($pipes[1]);
			$err = stream_get_contents($pipes[2]);
			fclose($pipes[1]); fclose($pipes[2]);
			$rtv = proc_close($process);

			echo $out, $err, $rtv;
		}
		*/
	}

	public function getCount($table)
	{
		$operation = [
			"db_name" => config('db.name'),
			"tb_name" => $table,
			"op_type" => 0
		];

		return $this->db_execute($operation);
	}

	public function select($table)
	{
		$operation = [
			"db_name" => config('db.name'),
			"tb_name" => $table,
			"op_type" => 1
		];

		$result = [];
		$dataset = $this->db_execute($operation);
		if ($dataset != 'null') {
			foreach (json_decode($dataset, true) as $value) {
				$row = $value["value"];
				$row["id"] = $value["key"];
				array_push($result, $row);
			}
		}
		return $result;
	}

	public function insert($table, $data)
	{
		$operation = [
			"db_name" => config('db.name'),
			"tb_name" => $table,
			"op_type" => 2,
			"data" => $data
		];

		return $this->db_execute($operation);
	}

	public function update($table, $id, $data)
	{
		$operation = [
			"db_name" => config('db.name'),
			"tb_name" => $table,
			"op_type" => 3,
			"id" => intval($id),
			"data" => $data
		];

		return $this->db_execute($operation);
	}

	public function remove($table)
	{
		$operation = [
			"db_name" => config('db.name'),
			"tb_name" => $table,
			"op_type" => 4,
			"id" => $id
		];

		return $this->db_execute($operation);
	}

	public function addTable($name)
	{
		$operation = [
			"db_name" => config('db.name'),
			"tb_name" => $name,
			"op_type" => 5
		];

		return $this->db_execute($operation);
	}

	public function removeTable($name)
	{
		$operation = [
			"db_name" => config('db.name'),
			"tb_name" => $name,
			"op_type" => 6,
		];

		return $this->db_execute($operation);
	}
}
