/*
 * @Author: TianZerL
 * @LastEditTime: 2020-07-19 15:31:55
 */

#include "M_DataDefine.h"

#include <stdlib.h>
#include <memory.h>

//该函数必须由调用者自行实现
extern mBool isEqualUserData(void *dataA, void *dataB);

mBool isEqualData(Data *dataA, Data *dataB)
{
    return isEqualUserData(dataA->data, dataB->data);
}

void dataFactor(Data *dataInfo, void *data, size_t dataSize)
{
    dataInfo->data = malloc(dataSize);
    memcpy(dataInfo->data, data, dataSize);
    dataInfo->dataSize = dataSize;
}