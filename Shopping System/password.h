#pragma once
#include<string>
class password {
public:
    bool checkUsername();
    bool checkPassword();
    void assembly();
    bool dChecking();
    void login();
    void myregister();
    void getUsername(std::string &demo);
private:
    std::string username;
    std::string password;
    int usernameLine = 0;
    int passwordLine = 0;
    int index;
};
