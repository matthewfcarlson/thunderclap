// STATUS: equivalent (tools/equiv.py level 3: 682 inputs, branch coverage 6/6)
// FUN_001fb260 @ 0x001fb260
inline void *operator new(unsigned int, void *p) throw() { return p; }

namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

class CDataHandlerObject;

struct HandlerObj {
    char pad[8];
    int f08;
    int f0c;
};

struct Inventory {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual HandlerObj *v3(content::LoadInventory::DynamicCaster<CDataHandlerObject> *caster, unsigned __int64 key);
    virtual void v4();
    virtual void v5(HandlerObj *h);
};

// The incoming pointer's stack slot doubles as the caster storage.
union InventoryArg {
    Inventory *inv;
    char caster[4];
};

extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
unsigned __int64 __cdecl FUN_002672f0(const char *s, int a, int b);
int __cdecl FUN_000964a0(char *buf, int size, const char *fmt, ...);

class DataLoader {
public:
    char pad0[0x2c];
    int cur;
    int end;
    void FUN_001faa80(int a, int b);
    bool FUN_001fb260(InventoryArg arg);
};

bool DataLoader::FUN_001fb260(InventoryArg arg)
{
    struct Frame {
        char buf[0x40];
        unsigned int cookie;
    } f;
    f.cookie = DAT_004d9968;
    if (cur < end) {
        Inventory *inv = arg.inv;
        for (int i = cur; i < end; i++) {
            FUN_000964a0(f.buf, 0x40, "GameDataHandlerRaw%d", i);
            unsigned __int64 key = FUN_002672f0(f.buf, 0, 0);
            HandlerObj *h = inv->v3(new (arg.caster) content::LoadInventory::DynamicCaster<CDataHandlerObject>, key);
            if (h) {
                FUN_001faa80(h->f0c, h->f08);
                inv->v5(h);
            }
        }
    }
    cur = end;
    __security_check_cookie(f.cookie);
    return true;
}
