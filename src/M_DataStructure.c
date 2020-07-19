/*
 * @Author: TianZerL
 * @LastEditTime: 2020-07-19 16:02:30
 */

#include "M_DataStructure.h"

#include <stdlib.h>

void initList(ListManger *listManger)
{
    listManger->head = NULL;
    listManger->tail = NULL;
}

void addNode(ListManger *listManger, Data *dataInfo)
{
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->dataInfo = (Data *)malloc(sizeof(Data));
    *newNode->dataInfo = *dataInfo;
    if (listManger->head == NULL)
    {
        newNode->next = newNode->pre = NULL;
        listManger->tail = listManger->head = newNode;
    }
    else
    {
        newNode->next = NULL;
        newNode->pre = listManger->tail;
        listManger->tail->next = newNode;
        listManger->tail = newNode;
    }
}

void addNodes(ListManger *listManger, Data *dataInfo, size_t count)
{
    for (int i = 0; i < count; i++)
        addNode(listManger, dataInfo + i);
}

void delNode(ListManger *listManger, Data *dataInfo)
{
    for (ListNode *it = listManger->head; it != NULL; it = it->next)
    {
        if (isEqualData(dataInfo, it->dataInfo))
        {
            if (it->pre == NULL)
                listManger->head = it->next;
            else
                it->pre->next = it->next;
            if (it->next == NULL)
                listManger->tail = it->pre;
            else
                it->next->pre = it->pre;
            free(it);
            break;
        }
    }
}

void delNodes(ListManger *listManger, Data *dataInfo)
{
    for (ListNode *it = listManger->head; it != NULL; it = it->next)
    {
        if (isEqualData(dataInfo, it->dataInfo))
        {
            if (it->pre == NULL)
                listManger->head = it->next;
            else
                it->pre->next = it->next;
            if (it->next == NULL)
                listManger->tail = it->pre;
            else
                it->next->pre = it->pre;
            free(it);
        }
    }
}

void updateNode(ListManger *listManger, Data *dataInfo, Data *newDataInfo)
{
    for (ListNode *it = listManger->head; it != NULL; it = it->next)
    {
        if (isEqualData(dataInfo, it->dataInfo))
        {
            *it->dataInfo = *newDataInfo;
            break;
        }
    }
}

void updateNodes(ListManger *listManger, Data *dataInfo, Data *newDataInfo)
{
    for (ListNode *it = listManger->head; it != NULL; it = it->next)
        if (isEqualData(dataInfo, it->dataInfo))
            *it->dataInfo = *newDataInfo;
}

ListNode *getNode(ListManger *listManger, Data *dataInfo)
{
    for (ListNode *it = listManger->head; it != NULL; it = it->next)
        if (isEqualData(dataInfo, it->dataInfo))
            return it;
}

void switchNode(ListNode *nodeA, ListNode *nodeB)
{
    Data tmp;
    tmp = *nodeA->dataInfo;
    *nodeA->dataInfo = *nodeB->dataInfo;
    *nodeB->dataInfo = tmp;
}

void sortList(ListManger *listManger, mBool (*compare)(Data *dataInfoA, Data *dataInfoB))
{
    ListNode *stop = listManger->tail;
    for (ListNode *count = listManger->head; stop != NULL && count != NULL; count = count->next, stop = stop->pre)
        for (ListNode *it = listManger->head;
             it != stop;
             it = it->next)
            {
                if (compare(it->dataInfo, it->next->dataInfo))
                    switchNode(it, it->next);
            }
}

void printList(ListManger *listManger, void (*printData)(void *data))
{
    for (ListNode *it = listManger->head; it != NULL; it = it->next)
        printData(it->dataInfo->data);
}

void destroyList(ListManger *listManger)
{
    ListNode *next = NULL;
    for (ListNode *it = listManger->head; it != NULL; it = next)
    {
        free(it->dataInfo->data);
        free(it->dataInfo);
        next = it->next;
        free(it);
    }
}