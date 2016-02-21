//============================================================================
// Name        : serverUserService.cpp
// Author      : Kiran Mohan E
// Version     : 1.0
// Copyright   : Copyright (c) 2016 Kiran Mohan E,  All Rights Reserved.
// Description : User Service using ONC RPC. This file defines the
//               user service remote protocol.
//============================================================================

#include <iostream>
#include <map>
#include <algorithm>
#include "userService.h" /* user-service.h generated by rpcgen
                            from lib-user-service/user-service.x*/
using namespace std;

const string USER_EXIST   =   "Username already exists. Try a different one";
const string REG_SUCCESS  =   "Registration successful";

const string adminUser      = "admin";
const string adminPassword  = "admin";

class ServerUserService {
    map<string, string> users;

    void addUser(const string & username, const string & password) {
        users.insert(pair<string, string>(username, password));
    }

public:

    ServerUserService() {
        // add default admin user
        addUser(adminUser,adminPassword);
    }

    const string & signUp(const string username, const string password) {
        if (users.find(username) != users.end()) {
            return USER_EXIST;
        } else {
            addUser(username, password);
            return REG_SUCCESS;
        }
    }

};

ServerUserService server;

result * sign_up_1_svc(user_profile * user, struct svc_req * svcReq) {
    static result res; /* must be static! */

    /* free the previous result */
    res.status = 0;
    if (res.resultData != NULL) {
        delete res.resultData;
    }

    const string & resStr = server.signUp(user->username, user->password);

    /*
     * do the work.
     */

    /* set the results and return */
    res.resultData = new char[MAXSTRINGLEN];
    strcpy(res.resultData, resStr.c_str());
    return &res;
}

//int main(int argc, char **argv) {
//    cout << "Starting user service server..." << endl;
//	int result = rpcServiceMain(argc, argv);
//	return 0;
//}
