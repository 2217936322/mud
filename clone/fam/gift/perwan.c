// xiandan.c �ɵ�

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIM "������" NOR, ({ "yingxiang wan", "yingxiang", "wan" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��ԲԲ�ĵ��裬��˵���˿��Ա�������ÿ��Ů������������鵤��ҩ��\n");
                set("value", 10000);
                set("unit", "��");
                set("only_do_effect", 1);
        }
}

int do_effect(object me)
{
        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);
        if (me->query("per") >= 40)
        {
                message_vision("$N��Ȼ�����ۡ�������һ�ء�\n", me);
                tell_object(me, "���������ǳ��Ŀࡣ\n");
        } else
        {
                tell_object(me, HIG "�㷢�������ò���Ư�����ˡ�\n" NOR);
                me->add("per", 1);
        }

        destruct(this_object());
        return 1;
}
