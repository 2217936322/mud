#include <ansi.h>
inherit ROOM;

int is_chat_room()
{
    return 1;
}

void create()
{
    set("short", NOR + WHT "��Ȧ" NOR);
    set("long", @LONG
������һ����������ҷ����ĵط������Ϲ���һ������(paizi)��
LONG);
    set("no_fight", 1);
    set("no_sleep_room",1);
    set("item_desc", ([
        "paizi" : WHT "���һ�𷢴�������̶���������硣\n" NOR,
    ]));
    set("exits", ([
        "south"   : __DIR__"majiu",
    ]));
    set("objects", ([
        "/adm/npc/horseboss":1,
    ]));
    setup();

    replace_program(ROOM);
}
