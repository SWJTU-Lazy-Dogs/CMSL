/*
 * @Author: TianZerL
 * @LastEditTime: 2020-07-19 17:23:08
 */

#ifndef _M_DISPLAY_
#define _M_DISPLAY_

#define ERROR_ITEM -1

typedef struct
{
    const char *info;
    void (*callback)(void);
} Item;

/*显示菜单并阻塞等待用户输入，返回用户选中项目的序号
itemCount：项目数
items：待显示的项目数组
header：自定义菜单头部
footer：自定义菜单尾部
format：自定义菜单项目的显示格式，若为NULL则默认采用 "%s\n"
*/
int menu(const int itemCount, char *const items[], const char *header, const char *footer, const char *format);

/*显示菜单并阻塞等待用户输入，调用用户选择的项目对应的回调函数，各项序号必须从1开始依次递增
itemCount：项目数
items：待显示的项目及其回调函数数组
errorHandler：当用户输入错误数据时的处理函数
header：自定义菜单头部
footer：自定义菜单尾部
format：自定义菜单项目的显示格式，若为NULL则默认采用 "%s\n"
*/
void menuWithCallback(const int itemCount, Item items[], void (*errorHandler)(void), const char *header, const char *footer, const char *format);

#endif