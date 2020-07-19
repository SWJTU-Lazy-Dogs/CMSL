/*
 * @Author: TianZerL
 * @LastEditTime: 2020-07-19 15:16:46
 */

#ifndef _M_IO_
#define _M_IO_

#include "M_DataStructure.h"

/*
保存数据到磁盘
@listManger：待保存的数据
@path：保存路径
返回成功与否
*/
mBool loadData(ListManger *listManger, const char *path);

/*
从磁盘读取数据
@listManger：用于存放读取的数据
@path：读取路径
返回成功与否
*/
mBool saveData(ListManger *listManger, const char *path);

#endif