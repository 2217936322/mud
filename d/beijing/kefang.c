inherit ROOM;

void create()
{
    set("short", "���ͷ�");
    set("long", @LONG
�����ǿ͵�Ķ��ͷ������úܼ򵥣������﷢�����򶷣����ϰ߰ߵ�㶼
��Ѫ����
LONG );
    set("exits", ([
        "west" : __DIR__"kediandayuan",
    ]));
    set("objects", ([
        __DIR__"npc/dubi" : 1,
        __DIR__"npc/lama" : 6,
    ]));
    setup();
    replace_program(ROOM);
}
