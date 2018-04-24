<?php

namespace App\System;

class Staff
{
	int display()
	{
		response = record["staffs"];
		cout << response;
		return 0;
	}

	int add()
	{
		record["staffs"].push_back(
		{
			{"jobNo", request["jobNo"]},
			{"name", request["name"]},
			{"gender", request["gender"]},
			{"nation", request["nation"]},
			{"nativePlace", request["nativePlace"]},
			{"department", request["department"]},
			{"postion", request["postion"]},
			{"birthday", request["birthday"]},
			{"contact", request["contact"]},
			{"address", request["address"]},
			{"salary", request["salary"]},
			{"entryTime", request["entryTime"]},
			{"status", request["status"]}
		});

		response ={{"code", 0}};
		cout << response;
		return 0;
	}

	int update()
	{
		data_index = request["staffID"];
		record["staffs"][data_index] =
		{
			{"jobNo", request["jobNo"]},
			{"name", request["name"]},
			{"gender", request["gender"]},
			{"nation", request["nation"]},
			{"nativePlace", request["nativePlace"]},
			{"department", request["department"]},
			{"postion", request["postion"]},
			{"birthday", request["birthday"]},
			{"contact", request["contact"]},
			{"address", request["address"]},
			{"salary", request["salary"]},
			{"entryTime", request["entryTime"]},
			{"status", request["status"]}
		};

		response ={{"code", 0}};
		cout << response;
		return 0;
	}
}