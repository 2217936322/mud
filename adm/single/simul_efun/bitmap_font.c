/*****************************************************************************
Copyright: 2020, Mud.Ren
File name: bitmap_font.c
Author: xuefeng@mud.ren
Version: v1.1
Date: 2020-02-20
Description:
    display ASCII and chinese with bitmap font for mudos and fluffos v2017
*****************************************************************************/
// �����ļ�(�������Ҫ�޸�·��)
#define HZK "/adm/etc/fonts/HZK"
#define ASC "/adm/etc/fonts/ASC"
// Ĭ��ǰ���ַ�
#define DEFAULT_FILL "��"
// Ĭ�ϱ����ַ�
#define DEFAULT_BG "--"
// Ĭ��ǰ����ɫ
#define DEFAULT_FCOLOR ""
// Ĭ�ϱ�����ɫ
#define DEFAULT_BGCOLOR ""
// Ĭ�ϵ����С
#define AUTO_SIZE 16
/**
 * �ַ����ֺš�������䡢������䡢ǰ��ɫ������ɫ
 */
varargs string bitmap_font(string str, int size, string fill, string bg, string fcolor, string bgcolor)
{
    int offset, fontsize, scale;
    int *mask = ({0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x2, 0x1});
    buffer char;
    string file, *out;
    // ��ǰ�����ֿ�16x12��16x14��16x16
    if (member_array(size, ({12, 14, 16, 32})) < 0)
        size = AUTO_SIZE;

    // ��������ռ�õ��ֽ���(֧��32x32���ֿ�)
    if (size < 16)
        fontsize = size * 2;
    else
        fontsize = size * size / 8;

    out = allocate(size, "");

    if (!sizeof(fill)) fill = DEFAULT_FILL;
    if (!sizeof(bg)) bg = DEFAULT_BG;
    if (sizeof(fill) != sizeof(bg))
    {
        fill = DEFAULT_FILL;
        bg = DEFAULT_BG;
    }

    if (!fcolor) fcolor = DEFAULT_FCOLOR;
    if (!bgcolor) bgcolor = DEFAULT_BGCOLOR;
    // 16x16�����ֿ��������
    if (size == 16)
        file = HZK + size + element_of(({"C", "F", "H", "K", "L", "S", "V", "X", "Y"}));
    else
        file = HZK + size;

    for (int k = 0; k < sizeof(str); k++)
    {
        if (mask[0] & str[k])
        {
            // ���룺���ֵĵ�һ���ֽ�-0xA0
            // λ�룺���ֵĵڶ����ֽ�-0xA0
            // offset = (94 * (���� - 1) + (λ�� - 1)) * fontsize;
            offset = fontsize * ((str[k] - 0xA1) * 94 + str[k+1] - 0xA1);
            char = read_buffer(file, offset, fontsize);
            scale = fontsize / size;
            k++;
        }
        else
        {
            // Ӣ��ÿ���ַ�ռ1�ֽ�
            offset = str[k] * size;
            char = read_buffer(ASC + size, offset, size);
            scale = 1;
        }

        if (!sizeof(char)) return "Can't read bytes from character lib.\n";

        //����ַ�
        for (int i = 0; i < sizeof(char); i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (mask[j] & char[i])
                    out[i / scale] += fcolor + fill;
                else
                    out[i / scale] += bgcolor + bg;
            }
        }
        // ����������ɫ����
        for (int i = 0; i < sizeof(out); i++)
        {
            out[i] = replace_string(out[i], fill + fcolor + fill, fill + fill);
            out[i] = replace_string(out[i], bg + bgcolor + bg, bg + bg);
        }
    }

    return implode(out, "\n");
}
