#include "DataBaseHandler.h"

namespace Handler
{
    DataBaseHandler* DataBaseHandler::mDataBaseHandeler = nullptr;

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
        
        handler->open(path);

        handler->mInit = true;
    }

    void DataBaseHandler::open(std::string path)
    {
        if (sqlite3_open(path.c_str(), &mDataBase))
        {
             
        } 
    }

    int DataBaseHandler::callback(void* data, int argc, char** argv, char** azColName) 
    {
	    DataBaseHandler* db = static_cast<DataBaseHandler*>(data);
	    for (int i = 0; i < argc; i++) {
		    //tmp_row.push_back(argv[i]);
	    }

	    //db->vAgro.push_back(tmp_row);

	    return 0;
    }

void  DataBaseHandler::request(std::string sql_req)
{
	// if (!vAgro.empty())
	// {
	// 	remove();
	// }

	int result = sqlite3_exec(mDataBase, sql_req.c_str(), callback, (void*)this, &messageError);

	if (result != SQLITE_OK) {
		sqlite3_free(messageError);
	}

}
}