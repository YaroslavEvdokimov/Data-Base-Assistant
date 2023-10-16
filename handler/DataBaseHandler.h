#pragma once 
#include <string>
//#include "../libs/sqlite/sqlite3.h" 
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

    private:
    DataBaseHandler(){};

    private:
    static DataBaseHandler* mDataBaseHandeler;
    bool mInit = false;
    sqlite3 *mDataBase;
};

}