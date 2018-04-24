<?php

namespace App\System;

class Sales
{
    $rate = 1.5; // Rate from payment to points

    int sell_item()
    {
        data_index = request["itemID"];
        int inventoryQuantity = record["items"][data_index]["inventoryQuantity"];
        record["items"][data_index]["inventoryQuantity"] = inventoryQuantity - 1;

        record["finance"].push_back(
        {
            {"name", "Sell Record"},
            {"income", record["items"][data_index]["salePrice"]},
            {"expenditure", 0},
            {"date", 
                {
                    {"year", request["year"]},
                    {"month", request["month"]},
                    {"day", request["day"]}
                }
            }
        });

        double points = record["items"][data_index]["salePrice"];

        data_index = request["customerID"];
        double totalPoints = record["customers"][data_index]["totalPoints"];

        record["customers"][data_index]["purchases"].push_back(
        {
            {"purchaseTime", request["time"]},
            {"payment", points},
            {"points", points * rate}
        });
        record["customers"][data_index]["totalPoints"] = totalPoints + points * rate;

        response ={{"code", 0}};
        cout << response;
        return 0;
    }

    int return_item()
    {
        data_index = request["itemID"];
        int inventoryQuantity = record["items"][data_index]["inventoryQuantity"];
        record["items"][data_index]["inventoryQuantity"] = inventoryQuantity + 1;

        record["finance"].push_back(
        {
            {"name", "Return Record"},
            {"income", 0},
            {"expenditure", record["items"][data_index]["salePrice"]},
            {"date", 
                {
                    {"year", request["year"]},
                    {"month", request["month"]},
                    {"day", request["day"]}
                }
            }
        });

        double points = record["items"][data_index]["salePrice"];

        data_index = request["customerID"];
        double totalPoints = record["customers"][data_index]["totalPoints"];
        points = - points;

        record["customers"][data_index]["purchases"].push_back(
        {
            {"purchaseTime", request["time"]},
            {"payment", points},
            {"points", points * rate}
        });
        record["customers"][data_index]["totalPoints"] = totalPoints + points * rate;

        response ={{"code", 0}};
        cout << response;
        return 0;
    }

    int input_limit()
    {
        response =
        {
            {"items", record["items"].size()},
            {"suppliers", record["suppliers"].size()},
            {"customers", record["customers"].size()}
        };
        cout << response;
        return 0;
    }
}
