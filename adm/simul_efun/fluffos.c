// ģ�� fluffos ���� efun
#ifndef FLUFFOS

mixed abs(mixed n)
{
    if (!floatp(n) && !intp(n))
        return 0;

    return (n < 0) ? -n : n;
}

mixed element_of(mixed *arr)
{
    return arr[random(sizeof(arr))];
}

#endif

#ifndef __PACKAGE_TRIM__
// ȥ��str���˵Ŀո�
string trim(string str)
{
    int len;

    while (str[0] == ' ')
        str = str[1.. < 1];
    while ((len = strlen(str) - 1) >= 0 && str[len] == ' ')
        str = str[0.. < 2];

    return str;
}
#endif
