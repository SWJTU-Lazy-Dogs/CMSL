/*
 * @Author: TianZerL
 * @LastEditTime: 2020-09-09 22:37:58
 */

//CMSL头文件
#include "M_DataDefine.h"
#include "M_DataStructure.h"
#include "M_IO.h"
#include "M_Display.h"
#include "M_DIY.h"

//系统头文件
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//解决VS对某些函数的安全性警告
#ifdef _MSC_VER
#define SCANF(F, V) scanf_s(F, V);
#else
#define SCANF(F, V) scanf(F, V);
#endif

//自定义交由Data结构体管理的数据类型
typedef struct
{
    char name[20];
    int id;
} myData;

//实现比较函数，该函数必须由使用者自行实现，声明于M_DataDefine.c
mBool isEqualUserData(void *dataA, void *dataB)
{
    return ((myData *)dataA)->id == ((myData *)dataB)->id;
}

//回调函数，自定义数据打印方式
void printData(void *data)
{
    printf(printFormat, ((myData *)data)->name, ((myData *)data)->id);
}

//回调函数，自定义数据比较方式
mBool compare(Data *dataInfoA, Data *dataInfoB)
{
    return ((myData *)dataInfoA->data)->id > ((myData *)dataInfoB->data)->id;
}

//创建数据
void createData(Data *dataInfo, const char *name, int id)
{
    myData data;
    memcpy(data.name, name, strlen(name) + 1);
    data.id = id;
    //生产Data结构体
    dataFactor(dataInfo, &data, sizeof(data));
}

//链表
ListManger list;

void addData(void)
{
    Data dataInfo;
    char buf[20];
    int id;

    printf(NamePrompt);
    fgets(buf, 20, stdin);
    buf[strlen(buf) - 1] = 0;

    printf(IdPrompt);
    SCANF("%d%*c", &id);

    createData(&dataInfo, buf, id);
    addNode(&list, &dataInfo);
}

void delData(void)
{
    Data dataInfo;
    int id;

    printf(IdPrompt);
    SCANF("%d%*c", &id);

    createData(&dataInfo, "tmp", id);
    delNode(&list, &dataInfo);
}

void updateData(void)
{
    Data dataInfo;
    int id;
    printf(IdPrompt);
    SCANF("%d%*c", &id);
    createData(&dataInfo, "tmp", id);

    Data newDataInfo;
    char buf[20];
    int newId;
    printf(NewNamePrompt);
    fgets(buf, 20, stdin);
    buf[strlen(buf) - 1] = 0;
    printf(NewIdPrompt);
    SCANF("%d%*c", &newId);
    createData(&newDataInfo, buf, newId);

    updateNode(&list, &dataInfo, &newDataInfo);
}

void sort(void)
{
    sortList(&list, compare);
}

void print(void)
{
    printList(&list, printData);
}

void save(void)
{
    saveData(&list, "./data.dat") ? printf(WriteSuccess) : printf(WriteFailure);
}

void load(void)
{
    loadData(&list, "./data.dat") ? printf(ReadSuccess) : printf(ReadFailure);
}

void quit(void)
{
    //销毁链表
    destroyList(&list);
    exit(0);
}

int main(void)
{
    Item items[] = {
        {Choice1, addData},
        {Choice2, delData},
        {Choice3, updateData},
        {Choice4, sort},
        {Choice5, print},
        {Choice6, save},
        {Choice7, load},
        {Choice8, quit}};

    const char *header = HeadBar;
    const char *footer = BottomBar;

    //初始化链表
    initList(&list);

    while(1)
        menuWithCallback(8, items, NULL, header, footer, NULL);
}
