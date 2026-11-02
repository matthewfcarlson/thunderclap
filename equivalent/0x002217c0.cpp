// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 6/6)
// FUN_002217c0 @ 0x002217c0
// FUN_002217c0: dispatch on a mode value
struct Item_2217c0 {
    char pad00[0xc];
    int idA;
    int idB;
};

struct Ctx_2217c0 {
    char pad00[0x18];
    int f18;
    int f1c;
    char buf[1];
};

extern "C" void __cdecl FUN_00221110(void *, void *);
void __cdecl FUN_00221200(Ctx_2217c0 *c, Item_2217c0 *i);
extern "C" void __cdecl FUN_00221560(void *, void *);
extern "C" void __cdecl FUN_002214b0(void *, void *);
void __cdecl FUN_002207c0(Ctx_2217c0 *c, char *buf, int id);

extern "C" void __cdecl FUN_002217c0(void *c, int mode, void *item)
{
    switch (mode) {
    case 5:
        FUN_00221110((Ctx_2217c0 *)((Ctx_2217c0 *)c), (Item_2217c0 *)((Item_2217c0 *)item));
        break;
    case 12:
        FUN_002214b0((Ctx_2217c0 *)((Ctx_2217c0 *)c), (Item_2217c0 *)((Item_2217c0 *)item));
        ((Ctx_2217c0 *)c)->f1c = ((Ctx_2217c0 *)c)->f18;
        FUN_002207c0(((Ctx_2217c0 *)c), ((Ctx_2217c0 *)c)->buf, ((Item_2217c0 *)item)->idA);
        ((Item_2217c0 *)item)->idA = -1;
        break;
    case 13:
        FUN_00221560((Ctx_2217c0 *)((Ctx_2217c0 *)c), (Item_2217c0 *)((Item_2217c0 *)item));
        ((Ctx_2217c0 *)c)->f1c = ((Ctx_2217c0 *)c)->f18;
        FUN_002207c0(((Ctx_2217c0 *)c), ((Ctx_2217c0 *)c)->buf, ((Item_2217c0 *)item)->idB);
        ((Item_2217c0 *)item)->idB = -1;
        break;
    default:
        FUN_00221200(((Ctx_2217c0 *)c), ((Item_2217c0 *)item));
        break;
    }
}
