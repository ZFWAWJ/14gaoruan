

/********************************************************************/
/* Copyright (C) SSE-USTC, 2014                                     */
/*                                                                  */
/*  FILE NAME             :  menu.h                                 */
/*  PRINCIPAL AUTHOR      :  Zhangfang                              */
/*  SUBSYSTEM NAME        :  menu                                   */
/*  MODULE NAME           :  LinkTable                              */
/*  LANGUAGE              :  C                                      */
/*  TARGET ENVIRONMENT    :  ANY                                    */
/*  DATE OF FIRST RELEASE :  2014/09/20                             */
/*  DESCRIPTION           :  interface of main                      */
/********************************************************************/

/*
 * Revision log:
 *
 * Created by Zhangfang,2014/09/20
 * Provide right Callback interface by Mengning,2012/09/17
 *
 */


#ifndef _MENU_H_
#define _MENU_H_

#include "linktable.h"
int Help();
int Quit();

extern tLinkTable * head;

/* data struct and its operations */

typedef struct DataNode
{
    tLinkTableNode * pNext;
    char*   cmd;
    char*   desc;
    int     (*handler)();
} tDataNode;

/* find a cmd in the linklist and return the datanode pointer */
tDataNode* FindCmd(tLinkTable * head, char * cmd);

/* show all cmd in listlist */
int ShowAllCmd(tLinkTable * head);

int InitMenuData(tLinkTable ** ppLinktable);



#endif 
