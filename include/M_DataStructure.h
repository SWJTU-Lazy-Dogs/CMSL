/*
 * @Author: TianZerL
 * @LastEditTime: 2020-07-19 17:22:41
 */

#ifndef _M_DATA_STRUCTURE_
#define _M_DATA_STRUCTURE_

#include "M_DataDefine.h"

//节点定义
typedef struct ListNode
{
    Data *dataInfo;
    struct ListNode *next;
    struct ListNode *pre;
} ListNode;

//链表定义
typedef struct
{
    ListNode *head;
    ListNode *tail;
} ListManger;

//初始化链表
void initList(ListManger *listManger);
//释放链表资源，将会释放所有由API内部分配的内存
void destroyList(ListManger *listManger);

/*
增加一个节点
listManger：目标链表
dataInfo：自定义节点数据
*/
void addNode(ListManger *listManger, Data *dataInfo);

/*
增加多个节点
listManger：目标链表
dataInfo：自定义节点数据数组
count：数据个数
*/
void addNodes(ListManger *listManger, Data *dataInfo, size_t count);

/*
删除一个和dataInfo数据相同的节点，若有多个相同，删除第一个
listManger：目标链表
dataInfo：自定义节点数据
*/
void delNode(ListManger *listManger, Data *dataInfo);

/*
删除和dataInfo数据相同的节点，若有多个相同，删除全部
listManger：目标链表
dataInfo：自定义节点数据
*/
void delNodes(ListManger *listManger, Data *dataInfo);

/*
更新和dataInfo数据相同的节点的数据为newDataInfo，若有多个相同，更新第一个
listManger：目标链表
dataInfo：自定义节点数据
newDataInfo：新数据
*/
void updateNode(ListManger *listManger, Data *dataInfo, Data *newDataInfo);

/*
更新和dataInfo数据相同的节点的数据为newDataInfo，若有多个相同，更新全部
listManger：目标链表
dataInfo：自定义节点数据
newDataInfo：新数据
*/
void updateNodes(ListManger *listManger, Data *dataInfo, Data *newDataInfo);

/*
获取第一个和dataInfo数据相同的节点
listManger：目标链表
dataInfo：自定义节点数据
*/
ListNode *getNode(ListManger *listManger, Data *dataInfo);

/*
交换两个节点
nodeA：节点A
nodeB：节点B
*/
void switchNode(ListNode *nodeA, ListNode *nodeB);

/*
对链表进行排序
listManger：目标链表
compare：自定义数据的比较方法
*/
void sortList(ListManger *listManger, mBool (*compare)(Data *dataInfoA, Data *dataInfoB));

/*
打印链表
listManger：目标链表
printData：自定义打印数据的方法
*/
void printList(ListManger *listManger, void (*printData)(void *data));

#endif