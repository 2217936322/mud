inherit F_CLEAN_UP;

int main(object me, string arg)
{
    if (!wizardp(me))
        return 0;

    /* clean up first */
    if (file_size("/dump/tmp_eval_file.c") != -1)
    rm ("/dump/tmp_eval_file.c");
    if (find_object("/dump/tmp_eval_file"))
    destruct(find_object("/dump/tmp_eval_file"));

    write_file("/dump/tmp_eval_file.c","mixed eval() { " + arg + "; }\n");
    printf("Result = %O\n", "/dump/tmp_eval_file"->eval());
    return 1;
}

int help(object me)
{
    if (!wizardp(me))
        return 0;

    write(@HELP
ָ���ʽ : eval <lpc code>

����ר�ã�����ʵ�ֹ��ܺ����С�

HELP);

    return 1;
}