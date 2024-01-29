#pragma once 
#include <string>
#include <iostream>
#include <sqlite/sqlite3.h>

namespace Handler
{

class DataBaseHandler
{
public:
    DataBaseHandler(DataBaseHandler&) = delete; 
    void operator=(const DataBaseHandler&) = delete;

    static void init(std::string path);
    static DataBaseHandler* get();
    void request(std::string sql);

private:
    DataBaseHandler(){};
    static int callback(void* data, int argc, char** argv, char** azColName);
    std::string open(std::string path);

private:
    static DataBaseHandler* mDataBaseHandeler;
    bool mInit = false;
    sqlite3 *mDataBase;
    char* messageError;
};

}