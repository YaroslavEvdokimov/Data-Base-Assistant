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
        
        if (handler->open(path) == SQLITE_OK)
        {
            handler->mInit = true;
        }else 
            return;
    }

    int DataBaseHandler::open(std::string path)
    {
        if (sqlite3_open(path.c_str(), &mDataBase) == SQLITE_ABORT)
        {
            std::cout << "Database is not open!" << std::endl;
            return SQLITE_ABORT;
        }
        
        return SQLITE_OK;
    }

    int DataBaseHandler::callback(void* data, int argc, char** argv, char** azColName) 
    {
	    DataBaseHandler* db = static_cast<DataBaseHandler*>(data);
        std::vector<std::string> tmp_row;
	    for (int i = 0; i < argc; i++) {
		    tmp_row.push_back(argv[i]);
	    }

        db->mData.push_back(tmp_row);

	    return 0;
    }

int  DataBaseHandler::request(std::string sql_req)
{
	if (!mData.empty())
	{
		mData.clear();
	}

	int result = sqlite3_exec(mDataBase, sql_req.c_str(), callback, (void*)this, &messageError);

	if (result != SQLITE_OK) {
		sqlite3_free(messageError);
		return SQLITE_ABORT;
	}else 
		return SQLITE_OK;

}

}