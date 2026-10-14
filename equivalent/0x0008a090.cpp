// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0008a090 @ 0x0008a090
struct Session {
    bool FUN_001d1cb0();
    bool FUN_001d2ba0(void *item, int a, int b);
    void FUN_001d1d30();
    void FUN_001d1d50(const char *name, void *entry);
    void FUN_001d19d0(int flag);
};
int __stdcall FUN_00089400(void *item);
Session *FUN_001d4c90();

struct Entry {
    char data[0x18];
};

class Holder {
public:
    char pad000[0x160];
    Entry entries[1];
    bool Run(void *item);
};

bool Holder::Run(void *item)
{
    int index = FUN_00089400(item);
    if (index == -1)
        return false;
    Session *s = FUN_001d4c90();
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
