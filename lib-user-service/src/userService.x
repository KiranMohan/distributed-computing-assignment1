/*============================================================================
// Name        : userService.x
// Author      : Kiran Mohan E
// Version     : 1.0
// Copyright   : Copyright (c) 2016 Kiran Mohan E,  All Rights Reserved.
// Description : User Service using ONC RPC. This file defines the 
//               user service remote protocol.
//==========================================================================*/

const MAXSTRINGLEN = 255; /* max length of a string */

typedef string String<MAXSTRINGLEN>; /* a string */

struct result {
    int status; /* 0 -> OK else not OK 8*/
    String resultData;
};

struct user_profile {
    String username;
    String password;
};

program USER_SERVICE {
   version USER_SERVICE_VERS {
     result SIGN_UP(user_profile userProfile) = 1;
   } = 1;
} = 0x20000001;
