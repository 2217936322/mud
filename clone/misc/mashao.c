/* mashao.c ���� */

#include <ansi.h>

inherit __DIR__"whistle";

void create()
{
    set_name( HIG "����" NOR, ({ "ma shao", "shao" }) );
    if ( clonep() )
        set_default_object( __FILE__ );
    else {
        set( "unit", "��" );
        set( "long", "����һ�������Ƴɵ����ڣ���������Զ�ھֵı�־��\n" );
        set( "family", 1 );
        set( "whistle", 5 );
    }

    setup();
}
