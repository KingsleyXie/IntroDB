<?php

return [
	'name' => 'db',
	'path' => '../app/db/',
	'file' => '../app/db/db.json',
	'exepath' => '../app/db/app.exe',
	'run' => 'cd ../app/db/ && app.exe ',
	'compile' => 'g++ -std=c++11 -o ../app/db/app.exe ../app/db/app.cpp',
	'empty' => '{"name":"db","tables":[]}'
];
