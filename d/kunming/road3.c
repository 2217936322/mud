inherit ROOM;

void create()
{
        set("short", "乱石滩");
        set("long", @LONG
这里怪石林立，路极不好走，不小心就要摔个跟斗，过了
这片石滩，就是长江岸边。
LONG);
        set("outdoors", "kunming");
        set("exits", ([
                "north" : __DIR__"road2", 
                "southwest" : __DIR__"road4",
                
        ]));

        setup();
        replace_program(ROOM);
}
