/*****************************************************************************
Copyright: 2020, Mud.Ren
File name: variables.c
Description: ����Աר�ã���ʾָ����������ȫ�ֱ�����ֵ
Author: xuefeng
*****************************************************************************/
inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
    object ob, ob1;
    string *vars, id;

    if (!wizardp(me))
        return 0;

    if (!arg || arg == "")
        ob = me;
    else if (sscanf(arg, "%s in %s", arg, id) == 2)
    {
        ob1 = present(id, environment(me));
        if (!ob1)
            ob1 = present(id, me);
        if (!ob1)
            return notify_fail("�����޴�����: " + id + "\n");
        if (!ob = present(arg, ob1))
            return notify_fail("�����������޴˶���: " + arg + "\n");
    }
    else if (arg == "here")
        ob = environment(me);
    else
    {
        arg = lower_case(arg);

        ob = present(arg, environment(me));
        if (!ob)
            ob = find_player(arg);
        if (!ob)
            ob = find_living(arg);
        if (!ob)
            ob = present(arg, me);
        if (!ob)
            return notify_fail("Data: �޷��ҵ��˶���: " + arg + "��\n");
    }
    if (sizeof(vars = variables(ob)))
    foreach(string var in vars)
        printf("%s = %O\n", var, fetch_variable(var, ob));

    return 1;
}

int help(object me)
{
    if (!wizardp(me))
        return 0;

    write(@LONG
ָ���ʽ: variables <���|����|here> <in ��һ�����>
ָ��˵��:
    ������������Թۿ���ָ����������ϣ���� data ָ����Բ鿴���������ֵ��
LONG );
    return  1;
}
