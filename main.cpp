#include <iostream>
#include <glog/logging.h>
#include <json/json.h>
#include <limits>
#include <cstring>
#include <cmath>
#include <iomanip>


using namespace std;


void testglog();

void testjson();


int main() {
    std::cout << "Hello, World!" << std::endl;
    testglog();
    testjson();
    return 0;
}


void testjson() {
    std::cout << "###############json###############" << std::endl;
    Json::Value jsonRoot; //定义根节点

    Json::Value jsonList; //定义一个子对象
    Json::Value jsonItem; //定义一个子对象
    jsonItem["item1"] = "one"; //添加数据
    jsonItem["item2"] = 2;

    jsonList.append(jsonItem);
    jsonItem.clear(); //清除jsonItem
    jsonItem["item1.0"] = 1.0;
    jsonItem["item2.0"] = 2.0;

    jsonList.append(jsonItem);

    jsonRoot["list"] = jsonList;
    cout << jsonRoot.toStyledString() << endl; //输出到控制台
}

void testglog() {

    std::cout << "###############glog###############" << std::endl;

    // Initialize Google's logging library.
    google::InitGoogleLogging("===GLOG===");
    google::SetLogDestination(google::INFO, "E://");
    // 设置日志路径  INFO WARNING ERROR FATAL
    // ...
    char str[20] = "hello log!";
    LOG(INFO) << "Found " << google::COUNTER << endl;
    LOG(INFO) << str;//<< " cookies";
    LOG(WARNING) << "warning test";
    LOG(ERROR) << "error test";

}
