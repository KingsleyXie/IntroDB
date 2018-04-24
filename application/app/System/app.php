<?php
if (!file_exists('db/app.exe'))
	shell_exec('g++ -std=c++11 -o db/app.exe db/app.cpp');

$operation = json_encode([
	"db_name" => "db",
	"tb_name" => "staffs",
	"op_type" => 0,
	"data" => [
		"foo" => "bar"
	]
]);

$operation = str_replace('"', '\"', $operation);
$cmd = "cd ./db && app.exe \"$operation\" 2>&1";

$output = shell_exec($cmd);
echo $output;





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
