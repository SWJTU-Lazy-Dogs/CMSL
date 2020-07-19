/*
 * @Author: TianZerL
 * @LastEditTime: 2020-07-19 15:28:46
 */

#ifndef _M_DATA_DEFINE_
#define _M_DATA_DEFINE_

#include <stddef.h>

#define mTrue (unsigned char)(1)
#define mFalse (unsigned char)(0)

typedef unsigned char mBool;

//定义自定义数据
typedef struct
{
    void *data;
    size_t dataSize;
} Data;

//比较自定义数据是否相等
mBool isEqualData(Data *dataA, Data *dataB);

/*
数据工厂
@dataInfo：带生成的Data结构体，需提前分配好内存
@data：将把data的一份拷贝分配给dataInfo，因此data的内存需要手动管理
@dataInfo：data的实际大小
*/
void dataFactor(Data *dataInfo, void *data, size_t dataSize);

#endif