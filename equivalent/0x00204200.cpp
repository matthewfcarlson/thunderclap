// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_00204200 @ 0x00204200
struct Query_204200 {
    int a;
    int b;
    int c;
};

struct Item_204200 {
    char pad0[0x54];
    short index;
    bool FUN_001c6660(Query_204200 *query);
};

struct Counter_204200 {
    int FUN_001c7520();
};

class Items_204200 {
public:
    char pad0[0x18];
    Counter_204200 counter;
    Item_204200 *FUN_001c7f80(int i);
};

struct Sys_204200 {
    int pad0;
    Items_204200 *items;
};

Sys_204200 *__cdecl FUN_001c3d90();

int __stdcall FUN_00204200(int a, int b, int c)
{
    if (FUN_001c3d90() == 0 || FUN_001c3d90()->items == 0) {
        return -1;
    }
    Items_204200 *items = FUN_001c3d90()->items;
    int count = items->counter.FUN_001c7520();
    Query_204200 q;
    q.a = a;
    q.b = b;
    q.c = c;
    for (int i = 0; i < count; i++) {
        Item_204200 *item = items->FUN_001c7f80(i);
        if (item != 0 && item->FUN_001c6660(&q)) {
            return item->index;
        }
    }
    return -1;
}
