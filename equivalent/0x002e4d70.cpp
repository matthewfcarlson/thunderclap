// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 12/12)
// FUN_002e4d70 @ 0x002e4d70
class Releasable {
public:
    virtual void v0();
    virtual void Release();      // slot 1
};

class Dispatcher {
public:
    char pad00[8];
    Releasable *pending;     // 0x08
    char pad0c[5];
    char enabled;            // 0x11
    unsigned short mode;     // 0x12
    char FUN_002e49a0(int a, int b);
    void FUN_002e1960(int a, int b, int c, int d, int e);
    void FUN_002e22c0(int a, int b, int c, int d, int e);
    void FUN_002e4d70(int a, int b, int c, int d, char direct, int e);
};

void Dispatcher::FUN_002e4d70(int a, int b, int c, int d, char direct, int e) {
    if (!FUN_002e49a0(b, c))
        return;
    if (enabled && direct && mode == 0)
        FUN_002e1960(a, b, c, d, e);
    else
        FUN_002e22c0(a, b, c, d, e);
    if (pending != 0) {
        pending->Release();
        pending = 0;
    }
}
