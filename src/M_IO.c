/*
 * @Author: TianZerL
 * @LastEditTime: 2020-07-11 12:49:50
 */

#include "M_IO.h"
#include "M_DataStructure.h"

#include <stdio.h>
#include <stdlib.h>

mBool loadData(ListManger *listManger, const char *path)
{
#ifdef _MSC_VER
    FILE* fp;
    errno_t err = fopen_s(&fp, path, "rb");
    if (err)
        return mFalse;
#else
    FILE* fp = fopen(path, "rb");
    if (fp == NULL)
        return mFalse;
#endif
    for (;;)
    {
        Data dataInfo;
        fread(&dataInfo.dataSize, sizeof(size_t), 1, fp);
        if (feof(fp))
            break;
        dataInfo.data = malloc(dataInfo.dataSize);
        fread(dataInfo.data, dataInfo.dataSize, 1, fp);
        addNode(listManger, &dataInfo);
    }
    fclose(fp);

    return mTrue;
}

mBool saveData(ListManger *listManger, const char *path)
{
#ifdef _MSC_VER
    FILE* fp;
    errno_t err = fopen_s(&fp, path, "wb");
    if (err)
        return mFalse;
#else
    FILE* fp = fopen(path, "wb");
    if (fp == NULL)
        return mFalse;
#endif
    for (ListNode *it = listManger->head; it != NULL; it = it->next)
    {
        fwrite(&it->dataInfo->dataSize, sizeof(size_t), 1, fp);
        fwrite(it->dataInfo->data, it->dataInfo->dataSize, 1, fp);
    }
    fclose(fp);

    return mTrue;
}