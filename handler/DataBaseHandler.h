#pragma once 
#include <string>
#include <iostream>
#include <sqlite/sqlite3.h>
#include "nlohmann/json.hpp"

namespace Handler
{

class DataBaseHandler
{
public:
    DataBaseHandler(DataBaseHandler&) = delete; 
    void operator=(const DataBaseHandler&) = delete;

    static void init(std::string path);
    static DataBaseHandler* get();
    int request(std::string sql);
    int open(std::string path);

private:
    DataBaseHandler(){};
    static int callback(void* data, int argc, char** argv, char** azColName);

private:
    static DataBaseHandler* mDataBaseHandeler;
    bool mInit = false;
    sqlite3 *mDataBase;
    char* messageError;
    nlohmann::json mData;
};

}