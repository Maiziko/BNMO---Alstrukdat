#include "arraydin.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    ArrayDin array;
    array = MakeArrayDin();
    Word line = toKata("Hello World");
    printf("%d\n", GetCapacity(array));
    printf("%d\n", Length(array));
    printf("%d\n", IsEmpty(array));
    InsertLast(&array, line);

    return 0;
}