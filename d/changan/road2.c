inherit ROOM;

void create()
{
        set("short", "��ٵ�");
        set("long", @LONG
����һ��������ֱ����������Ĵ�ٵ����������˶���������������
�����ٵ����ǿ�㣬����ݵ���ʮ���ۡ�����ֱ�ﳤ���Ķ��ţ�������
���������ųǡ�
LONG);
        set("outdoors", "changan");
        set("exits",  ([
                "east"   :  "/d/luoyang/guandaow4",
                "west"   :  __DIR__"zhongnan",
        ]));

        setup();
        replace_program(ROOM);
}
