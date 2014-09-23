
/********************************************************************/
/* Copyright (C) SSE-USTC, 2014                                     */
/*                                                                  */
/*  FILE NAME             :  menu.c                                 */
/*  PRINCIPAL AUTHOR      :  Zhangfang                              */
/*  SUBSYSTEM NAME        :  menu                                   */
/*  MODULE NAME           :  LinkTable                              */
/*  LANGUAGE              :  C                                      */
/*  TARGET ENVIRONMENT    :  ANY                                    */
/*  DATE OF FIRST RELEASE :  2014/09/20                             */
/*  DESCRIPTION           :  interface of menu                      */
/********************************************************************/

/*
 * Revision log:
 *
 * Created by Zhangfang,2014/09/20
 * Provide right Callback interface by Mengning,2012/09/17
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include "linktable.h"
#include "menu.h"

/* menu program */
tLinkTable * head = NULL;

int Help()
{
    ShowAllCmd(head);
    return 0; 
}

int Quit()
{
    exit(0);
}

/* find a cmd in the linklist and return the datanode pointer */
tDataNode* FindCmd(tLinkTable * head, char * cmd)
{
    tDataNode * pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        if(!strcmp(pNode->cmd, cmd))
        {
            return  pNode;  
        }
        pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
    }
    return NULL;
}

/* show all cmd in listlist */
int ShowAllCmd(tLinkTable * head)
{
    tDataNode * pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        printf("%s - %s\n", pNode->cmd, pNode->desc);
        pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
    }
    return 0;
}

int InitMenuData(tLinkTable ** ppLinktable)
{
    *ppLinktable = CreateLinkTable();
    tDataNode* pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "help";
    pNode->desc = "Menu List:";
    pNode->handler = Help;
    AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "version";
    pNode->desc = "Menu Program V1.0";
    pNode->handler = NULL; 
    AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "quit";
    pNode->desc = "Quit from Menu Program V1.0";
    pNode->handler = Quit; 
    AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);
 
    return 0; 
}

