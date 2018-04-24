<?php

namespace Tests\Unit;

use Tests\TestCase;
use Illuminate\Foundation\Testing\WithFaker;

use App\System\Db;

class DbExecTest extends TestCase
{
    /**
     * A basic test example.
     *
     * @return void
     */
    public function testExample()
    {
        $this->assertTrue(true);
    }

    public function getCountTest()
    {
        $db = new Db;
        $this->assertTrue($db->getCount("staffs") == 1);
    }
}
