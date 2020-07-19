/*
 * @Author: TianZerL
 * @LastEditTime: 2020-07-19 16:22:17
 */

#include "M_DataDefine.h"
#include "M_DataStructure.h"
#include "M_IO.h"
#include "M_Display.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���VS��ĳЩ�����İ�ȫ�Ծ���
#ifdef _MSC_VER
#define SCANF(F, V) scanf_s(F, V);
#else
#define SCANF(F, V) scanf(F, V);
#endif

//�Զ�����������
typedef struct
{
    char name[20];
    int id;
} myData;

//ʵ�ֱȽϺ������ú���������ʹ��������ʵ�֣�������M_DataDefine.c
mBool isEqualUserData(void *dataA, void *dataB)
{
    return ((myData *)dataA)->id == ((myData *)dataB)->id;
}

//�ص��������Զ������ݴ�ӡ��ʽ
void printData(void *data)
{
    printf("name: %s\nid: %d\n", ((myData *)data)->name, ((myData *)data)->id);
}

//�ص��������Զ������ݱȽϷ�ʽ
mBool compare(Data *dataInfoA, Data *dataInfoB)
{
    return ((myData *)dataInfoA->data)->id > ((myData *)dataInfoB->data)->id;
}

//��������
void createData(Data *dataInfo, const char *name, int id)
{
    myData data;
    memcpy(data.name, name, strlen(name) + 1);
    data.id = id;
    dataFactor(dataInfo, &data, sizeof(data));
}

//����
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
    saveData(&list, "./data.dat") ? printf("����ɹ�\n") : printf("����ʧ��\n");
}

void load()
{
    loadData(&list, "./data.dat") ? printf("��ȡ�ɹ�\n") : printf("��ȡʧ��\n");
}

void quit()
{
    destroyList(&list);
    exit(0);
}

int main(void)
{
    Item items[] = {
        {"1.��������", addData},
        {"2.ɾ������", delData},
        {"3.�޸�����", updateData},
        {"4.��������", sort},
        {"5.��ӡ����", print},
        {"6.��������", save},
        {"7.��ȡ����", load},
        {"8.�˳�", quit}};

    char *header = "**********\n";
    char *footer = "**********\n";

    initList(&list);

    for (;;)
    {
        menuWithCallback(8, items, NULL, header, footer, NULL);
    }
}