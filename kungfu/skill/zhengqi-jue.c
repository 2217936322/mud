// zhengqi-jue.c

inherit SKILL;

#include <ansi.h>

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int practice_skill(object me)
{
    return notify_fail("������ֻ�ܿ�ѧ(study)����ߡ�\n");
}

void skill_improved(object me)
{
    int sklv = me->query_skill("zhengqi-jue", 1);
    tell_object(me, HIR "������ĵ���һ������֮����\n" NOR );
    me->add("shen", sklv * sklv);
}

int valid_learn(object me)
{
    return ::valid_learn(me);
}
