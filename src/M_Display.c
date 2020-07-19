/*
 * @Author: TianZerL
 * @LastEditTime: 2020-07-19 15:10:13
 */

#include "M_Display.h"

#include <stdio.h>

int menu(const int itemCount, char *const items[], const char *header, const char *footer, const char *format)
{
    char *printFormat = (char *)format;
    if (format == NULL)
        printFormat = "%s\n";

    if (header != NULL)
        printf(header);

    for (int i = 0; i < itemCount; i++)
        printf(printFormat, items[i]);

    if (footer != NULL)
        printf(footer);

    int ret = ERROR_ITEM;

#ifdef _MSC_VER
    scanf_s("%d", &ret);
#else
    scanf("%d", &ret);
#endif
    while (getchar() != '\n')
        ;

    if (ret < 1 || ret > itemCount)
        ret = ERROR_ITEM;

    return ret;
}

void menuWithCallback(const int itemCount, Item items[], void (*errorHandler)(void), const char *header, const char *footer, const char *format)
{
    char *printFormat = (char *)format;
    if (format == NULL)
        printFormat = "%s\n";

    if (header != NULL)
        printf(header);

    for (int i = 0; i < itemCount; i++)
        printf(printFormat, items[i].info);

    if (footer != NULL)
        printf(footer);

    int rst = ERROR_ITEM;

#ifdef _MSC_VER
    scanf_s("%d", &rst);
#else
    scanf("%d", &rst);
#endif
    while (getchar() != '\n')
        ;

    if (rst < 1 || rst > itemCount)
    {
        if (errorHandler == NULL)
            printf("error item\n");
        else
            errorHandler();
        
        return;
    }

    items[rst - 1].callback();
}