#pragma execution_character_set("utf-8") //默认使用UTF8  
#include "json.h"


using namespace cocos2d::network;

//获得指定json文件内容
string getJsonData(string fileName){
	auto path = FileUtils::getInstance()->fullPathForFilename((JSON_PATH+fileName).c_str());
	ssize_t size = 0;
	unsigned char* titlech = FileUtils::getInstance()->getFileData(path, "r", &size);
	string str = string((const char*)titlech, size);

	return str;
}

//从指定json内容中查找对应值
string getJsonKeyData(string json, string key){
	//json = "http://keochoi.duapp.com/version.json";
	rapidjson::Document d;
	d.Parse<0>(json.c_str());
	if (d.IsObject() && d.HasMember(key.c_str())) {
		return d[key.c_str()].GetString();
	}
	
	return "failed!";
}


HttpRequest * request = new HttpRequest();
request->setUrl("http://keochoi.duapp.com/version.json");
request->setRequestType(HttpRequest::Type::GET);
request->setResponseCallback(CC_CALLBACK_2(HelloWorld::onHttpRequestCompleted, this));
request->setTag("GET test");
cocos2d::network::HttpClient::getInstance()->send(request);
request->release();



//  这是个静态方法，得到一个httpClient实例
HttpRequest* httpClient = new HttpRequest();
//    创建一个CCHttpRequest对象
//    设置请求类型
httpClient->setRequestType(HttpRequest::kHttpGet);
//  设置请求Url(可以更具需要从json 或xml,甚至html里解析获得到这个图片url)
httpReq->setUrl("http://avatar.csdn.net/A/6/5/1_qqxj2012.jpg");
//    请求完成后回调
httpReq->setResponseCallback(this, callfuncND_selector(HelloWorld::onGetFinished));
//   为请求设置标签,后面可以根据这个标签来获取我们要的数据
httpReq->setTag("PicGet");
//    设置连接超时时间
httpClient->setTimeoutForConnect(30);
httpClient->send(httpReq);
httpReq->release();
httpReq = NULL;
