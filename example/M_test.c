/*
 * @Author: TianZerL
 * @LastEditTime: 2020-07-19 17:29:44
 */

#include "M_DataDefine.h"
#include "M_DataStructure.h"
#include "M_IO.h"
#include "M_Display.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//解决VS对某些函数的安全性警告
#ifdef _MSC_VER
#define SCANF(F, V) scanf_s(F, V);
#else
#define SCANF(F, V) scanf(F, V);
#endif

//自定义数据类型
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
    printf("name: %s\nid: %d\n", ((myData *)data)->name, ((myData *)data)->id);
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
    dataFactor(dataInfo, &data, sizeof(data));
}

//链表
ListManger list;

void addData()
{
    Data dataInfo;
    char buf[20];
    int id;
    printf("name:\n");
    fgets(buf, 20, stdin);
    buf[strlen(buf) - 1] = 0;
    printf("id:\n");
    SCANF("%d%*c", &id);
    createData(&dataInfo, buf, id);
    addNode(&list, &dataInfo);
}

void delData()
{
    Data dataInfo;
    int id;
    printf("id:\n");
    SCANF("%d%*c", &id);
    createData(&dataInfo, "tmp", id);
    delNode(&list, &dataInfo);
}

void updateData()
{
    Data dataInfo;
    int id;
    printf("id:\n");
    SCANF("%d%*c", &id);
    createData(&dataInfo, "tmp", id);

    Data newDataInfo;
    char buf[20];
    int newId;
    printf("new name:\n");
    fgets(buf, 20, stdin);
    buf[strlen(buf) - 1] = 0;
    printf("new id:\n");
    SCANF("%d%*c", &newId);
    createData(&newDataInfo, buf, newId);

    updateNode(&list, &dataInfo, &newDataInfo);
}

void sort()
{
    sortList(&list, compare);
}

void print()
{
    printList(&list, printData);
}

void save()
{
    saveData(&list, "./data.dat") ? printf("保存成功\n") : printf("保存失败\n");
}

void load()
{
    loadData(&list, "./data.dat") ? printf("读取成功\n") : printf("读取失败\n");
}

void quit()
{
    destroyList(&list);
    exit(0);
}

int main(void)
{
    Item items[] = {
        {"1.添加数据", addData},
        {"2.删除数据", delData},
        {"3.修改数据", updateData},
        {"4.数据排序", sort},
        {"5.打印数据", print},
        {"6.保存数据", save},
        {"7.读取数据", load},
        {"8.退出", quit}};

    char *header = "**********\n";
    char *footer = "**********\n";

    initList(&list);

    for (;;)
    {
        menuWithCallback(8, items, NULL, header, footer, NULL);
    }
}