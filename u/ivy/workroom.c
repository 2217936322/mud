#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�ƶ�");
        set("long", HIW"
    �����Ǿ������⣬������ĵط�����ֻ��������Ʈ����
���Ŀ�������
\n");
        set("exits", ([
                "down"  : "/d/city/tree",
                "up"  : "/d/sky/tianmen",
        ]));

        set("objects",([
                "/d/city/npc/yanruyu" : 1,
        ]));

        set("valid_startroom", 1);
        set("outdoors", "sky");
        setup();
        replace_program(ROOM);
}
