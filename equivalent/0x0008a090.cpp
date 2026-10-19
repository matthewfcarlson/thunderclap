// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0008a090 @ 0x0008a090
struct Session_8a090 {
    bool FUN_001d1cb0();
    bool FUN_001d2ba0(void *item, int a, int b);
    void FUN_001d1d30();
    void FUN_001d1d50(const char *name, void *entry);
    void FUN_001d19d0(int flag);
};
struct ThisCall_00089400 {
    int FUN_00089400(void *item);
};
Session_8a090 *FUN_001d4c90();

struct Entry_8a090 {
    char data[0x18];
};

class Holder_8a090 {
public:
    char pad000[0x160];
    Entry_8a090 entries[1];
    bool Run(void *item);
};

bool Holder_8a090::Run(void *item)
{
    int index = ((ThisCall_00089400*)(this))->FUN_00089400(item);
    if (index == -1)
        return false;
    Session_8a090 *s = FUN_001d4c90();
    if (s != 0 && s->FUN_001d1cb0()) {
        if (!s->FUN_001d2ba0(item, 0, 1)) {
            s->FUN_001d1d30();
            return false;
        }
        s->FUN_001d1d50("info", &entries[index]);
        s->FUN_001d19d0(1);
        s->FUN_001d1d30();
        return true;
    }
    return false;
}
