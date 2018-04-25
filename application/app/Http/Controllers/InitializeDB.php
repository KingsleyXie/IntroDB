<?php
namespace App;

use App\Db;

$db = new Db;

$db->addTable("customers");
$db->addTable("finance");
$db->addTable("items");
$db->addTable("staffs");
$db->addTable("suppliers");
