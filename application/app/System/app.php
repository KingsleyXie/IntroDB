<?php
class Db
{
	private $operation, $db_name = "db";

	function __construct()
	{
		if (!file_exists('db/app.exe'))
			shell_exec('g++ -std=c++11 -o db/app.exe db/app.cpp');

		$this->operation = ["db_name" => $this->db_name];
	}

	private function db_execute()
	{
		$this->operation = str_replace('"', '\"', $this->operation);

		$cmd = 'cd ./db && app.exe "' . $this->operation . '" 2>&1';
		$result = shell_exec($cmd);

		return $result;
	}

	public function getCount($table)
	{
		$this->operation["tb_name"] = $table;
		$this->operation["op_type"] = 0;

		return $this->db_execute();
	}

	public function select($table)
	{
		$this->operation["tb_name"] = $table;
		$this->operation["op_type"] = 1;

		return $this->db_execute();
	}

	public function insert($table, $data)
	{
		$this->operation["tb_name"] = $table;
		$this->operation["op_type"] = 2;
		$this->operation["data"] = $data;

		return $this->db_execute();
	}

	public function update($table, $id, $data)
	{
		$this->operation["tb_name"] = $table;
		$this->operation["op_type"] = 3;
		$this->operation["id"] = $id;
		$this->operation["data"] = $data;

		return $this->db_execute();
	}

	public function remove($table)
	{
		$this->operation["tb_name"] = $table;
		$this->operation["op_type"] = 4;
		$this->operation["id"] = $id;

		return $this->db_execute();
	}

	public function addTable($name)
	{
		$this->operation["tb_name"] = $name;
		$this->operation["op_type"] = 5;

		return $this->db_execute();
	}

	public function removeTable($name)
	{
		$this->operation["tb_name"] = $name;
		$this->operation["op_type"] = 6;

		return $this->db_execute();
	}
}





/*
Another way to process both stdin and stdout:


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
