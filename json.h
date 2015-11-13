#ifndef __JSON_H__
#define __JSON_H__

#include "gameConst.h"
#include "json/rapidjson.h"
#include "json/document.h"

#include "cocos-ext.h"
#include "network/HttpClient.h"


string getJsonData(string fileName);
string getJsonKeyData(string json, string key);


//auto ccc=HttpClient


#endif
