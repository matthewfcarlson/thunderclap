// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 4/4)
// FUN_0025d070 @ 0x0025d070
// 0x0025d070: claim the global slot for obj, reporting the current owner state through the out parameters
struct Slot {
    char pad00[4];
    unsigned int limit;
    int field_08;
    int current;
    void* owner;
};

struct Obj {
    char pad00[0x14];
    int link;
    int claimed;
};

extern Slot* DAT_004e5ce0;
int __cdecl FUN_0024c2f0();
unsigned int __cdecl FUN_0026fd80(unsigned int a, int b, int* c);

bool FUN_0025d070(Obj* obj, int arg2, unsigned int arg3, int unused, int* out5, int* out6, unsigned int* out7)
{
    if (DAT_004e5ce0->owner != 0)
        return false;
    *out5 = DAT_004e5ce0->current;
    *out6 = 1;
    if (arg3 > DAT_004e5ce0->limit)
        *out7 = FUN_0026fd80(DAT_004e5ce0->limit, FUN_0024c2f0(), &obj->link);
    else
        *out7 = arg3;
    DAT_004e5ce0->field_08 = arg2;
    obj->claimed = 1;
    DAT_004e5ce0->owner = obj;
    return true;
}
