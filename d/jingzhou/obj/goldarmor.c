
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( "黄金甲", ({"goldarmor","jinarmor", "jinjia" }) );
        set_weight(35000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 20000);
                set("material", "leather");
                set("armor_prop/armor", 50);
        }
        setup();
}

