// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 10/10)
// FUN_001ebfd0 @ 0x001ebfd0
struct NameList_1ebfd0 {
    char data[0x48];
    void FUN_001ef320();
    void FUN_001ef370(const char *name);
    void FUN_001ef350();
};

struct Key_1ebfd0 {
    unsigned int lo;
    unsigned int hi;
};

struct Target_1ebfd0 {
    char pad00[8];
    Key_1ebfd0 key;
    char pad10[0x11c - 0x10];
    void *handle;
};

struct Dispatcher_1ebfd0 {
    void FUN_001efe20(NameList_1ebfd0 *names, Key_1ebfd0 *key, int a, float scale);
};

struct Registry_1ebfd0 {
    Dispatcher_1ebfd0 *dispatcher;
    char pad04[4];
    unsigned char enabled;
};

extern unsigned int DAT_004dc0e0;
extern unsigned int DAT_004dc0e4;
extern Registry_1ebfd0 *DAT_004e36d8;

void __stdcall FUN_001ebfd0(Target_1ebfd0 *target, int a)
{
    if (!target)
        return;
    if (!target->handle)
        return;
    Key_1ebfd0 *key = &target->key;
    if (key->lo != DAT_004dc0e0 || key->hi != DAT_004dc0e4)
        return;
    NameList_1ebfd0 names;
    names.FUN_001ef320();
    names.FUN_001ef370("Objects");
    names.FUN_001ef370("FE");
    Registry_1ebfd0 *registry = DAT_004e36d8;
    if (registry->enabled)
        registry->dispatcher->FUN_001efe20(&names, key, a, 100.0f);
    names.FUN_001ef350();
}
