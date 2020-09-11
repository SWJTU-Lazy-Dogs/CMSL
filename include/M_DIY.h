/*
 * @Author: qzmlgfj 
 * @Date: 2020-09-11 16:35:12 
 * @Last Modified by: qzmlgfj
 * @Last Modified time: 2020-09-11 17:20:28
 */

/*
 * 这是方便用户自定义诸如文字菜单之类的头文件，方便快速让程序改头换面混过只看演示的验收
 * 请善用代码重构功能
*/

/*
 * 菜单部分
*/

const char Choice1[] = "1.添加数据";
const char Choice2[] = "2.删除数据";
const char Choice3[] = "3.修改数据";
const char Choice4[] = "4.数据排序";
const char Choice5[] = "5.打印数据";
const char Choice6[] = "6.保存数据";
const char Choice7[] = "7.读取数据";
const char Choice8[] = "8.退出";
 
const char HeadBar[] = "**********\n";
const char BottomBar[] = "**********\n";

/*
 * 输入输出格式部分
*/

const char printFormat[] = "name: %s\nid: %d\n";
const char NamePrompt[] = "name:\n";
const char IdPrompt[] = "id:\n";

const char NewNamePrompt[] = "new name:\n";
const char NewIdPrompt[] = "new id:\n";

/*
 * 运行结果提示
*/

const char ReadSuccess[] = "读取成功\n";
const char WriteSuccess[] = "保存成功\n";

const char ReadFailure[] = "读取失败\n";
const char WriteFailure[] = "保存失败\n";
