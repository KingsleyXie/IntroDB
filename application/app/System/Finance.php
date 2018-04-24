<?php

namespace App\System;

class Finance
{
	int display()
	{
		response = record["finance"];
		cout << response;
		return 0;
	}

	int add()
	{
		record["finance"].push_back(
		{
			{"name", request["financeName"]},
			{"income", request["income"]},
			{"expenditure", request["expenditure"]},
			{"date", 
				{
					{"year", request["year"]},
					{"month", request["month"]},
					{"day", request["day"]}
				}
			}
		});

		response ={{"code", 0}};
		cout << response;
		return 0;
	}
}