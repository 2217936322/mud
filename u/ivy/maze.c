#include <ansi.h>

inherit ROOM;

varargs void create(int x, int y, int z)
{
    set("short", "�����Թ�");
    set("long", "�����������Թ����������֪�������Ķ��ߡ�\n");
    set("exits", ([
        "north":__DIR__ "maze/" + x + "," + (y + 1) + "," + z,
        "south":__DIR__ "maze/" + x + "," + (y - 1) + "," + z,
        "west":__DIR__ "maze/" + (x - 1) + "," + y + "," + z,
        "east":__DIR__ "maze/" + (x + 1) + "," + y + "," + z,
    ]));
    set("maze", "maze");
    set("outdoors", "maze");

    if (!random(100))
    {
        set("long", "�����������Թ������Ѿ���֪���Լ��ķ����ˣ�������һ��ָʾ��(board)��\n");
        set("item_desc", ([
            "board":"�Թ�������ʾ��" HIY "ɱ��BOSS" NOR "��\n",
        ]));
    }

    if (!random(10))
    {
        set("objects", ([
            "/clone/beast/qingshe":1,
        ]));
    }

    if (!random(20))
    {
        set("objects", ([
            "/clone/beast/wubushe":1,
        ]));
    }

    if (!random(30))
    {
        set("objects", ([
            "/clone/beast/yanjingshe":1,
        ]));
    }

    setup();
}
