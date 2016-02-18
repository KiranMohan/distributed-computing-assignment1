/*============================================================================
// Name        : userService.x
// Author      : Kiran Mohan E
// Version     : 1.0
// Copyright   : Copyright (c) 2016 Kiran Mohan E,  All Rights Reserved.
// Description : User Service using ONC RPC. This file defines the 
//               user service remote protocol.
//==========================================================================*/

program MESSAGEPROG {
   version PRINTMESSAGEVERS {
     int PRINTMESSAGE(string) = 1;
   } = 1;
} = 0x20000001;
