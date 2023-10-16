#include "DataBaseHandler.h"

namespace Handler
{
    DataBaseHandler *DataBaseHandler::get()
    {
        if (mDataBaseHandeler == nullptr)
        {
            mDataBaseHandeler = new DataBaseHandler;
        }
        return mDataBaseHandeler;
    }

     void DataBaseHandler::init(std::string path)
     {
        auto handler = get();
        
        if (sqlite3_open(path.c_str(), &handler->mDataBase))
        {
             
        } 

        handler->mInit = true;
     }
}