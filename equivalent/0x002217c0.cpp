// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 6/6)
// FUN_002217c0 @ 0x002217c0
// FUN_002217c0: dispatch on a mode value
struct Item {
    char pad00[0xc];
    int idA;
    int idB;
};

struct Ctx {
    char pad00[0x18];
    int f18;
    int f1c;
    char buf[1];
};

void __cdecl FUN_00221110(Ctx *c, Item *i);
void __cdecl FUN_00221200(Ctx *c, Item *i);
void __cdecl FUN_00221560(Ctx *c, Item *i);
void __cdecl FUN_002214b0(Ctx *c, Item *i);
void __cdecl FUN_002207c0(Ctx *c, char *buf, int id);

void __cdecl FUN_002217c0(Ctx *c, int mode, Item *item)
{
    switch (mode) {
    case 5:
        FUN_00221110(c, item);
        break;
    case 12:
        FUN_002214b0(c, item);
        c->f1c = c->f18;
        FUN_002207c0(c, c->buf, item->idA);
        item->idA = -1;
        break;
    case 13:
        FUN_00221560(c, item);
        c->f1c = c->f18;
        FUN_002207c0(c, c->buf, item->idB);
        item->idB = -1;
        break;
    default:
        FUN_00221200(c, item);
        break;
    }
}
