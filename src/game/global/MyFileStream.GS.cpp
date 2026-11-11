// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001fa9c0..0x001fb3f0 (kind game, layer game, confidence high), dominant class MyFileStream
#include "tree_prelude.h"
#include "decls/address.h"
#define TREE_TU_BEGIN namespace fn_f428f7d4 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f428f7d4 {} using namespace fn_f428f7d4;
#include "game/global.h"

// ---- declarations shared by the functions below
inline void *operator new(size_t, void *p) throw() { return p; }
namespace fn_f428f7d4 {
namespace content { namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
} }
class CDataHandlerObject;
struct HandlerObj {
    char pad[8];
    int f08;
    int f0c;
};
struct Inventory_1fb260 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual HandlerObj *v3(content::LoadInventory::DynamicCaster<CDataHandlerObject> *caster, unsigned __int64 key);
    virtual void v4();
    virtual void v5(HandlerObj *h);
};
union InventoryArg_1fb260 {
    Inventory_1fb260 *inv;
    char caster[4];
};
int __cdecl FUN_000964a0(char *buf, int size, const char *fmt, ...);
class DataLoader_1fb260 {
public:
    char pad0[0x2c];
    int cur;
    int end;
    void FUN_001faa80(int a, int b);
    bool FUN_001fb260(InventoryArg_1fb260 arg);
};
struct Inventory_1fb300 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual HandlerObj *v3(content::LoadInventory::DynamicCaster<CDataHandlerObject> *caster, unsigned __int64 key);
    virtual void v4();
    virtual void v5(HandlerObj *h);
};
union InventoryArg_1fb300 {
    Inventory_1fb300 *inv;
    char caster[4];
};
class DataLoader_1fb300 {
public:
    char pad0[0x2c];
    int cur;
    int end;
    void FUN_001fab00(int a, int b);
    bool FUN_001fb300(InventoryArg_1fb300 arg);
};


// 0x001fb260 FUN_001fb260 (153 B): equivalent/0x001fb260.cpp
// sym: ?FUN_001fb260@DataLoader_1fb260@fn_f428f7d4@@QAE_NTInventoryArg_1fb260@2@@Z @574fed1393ab @w296b47dd35e4
// STATUS: equivalent (tools/equiv.py level 3: 4502 inputs, branch coverage 6/6)
// FUN_001fb260 @ 0x001fb260
bool DataLoader_1fb260::FUN_001fb260(InventoryArg_1fb260 arg)
{
    struct Frame {
        char buf[0x40];
    } f;
    if (cur < end) {
        Inventory_1fb260 *inv = arg.inv;
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
    return true;
}


// 0x001fb300 FUN_001fb300 (153 B): equivalent/0x001fb300.cpp
// sym: ?FUN_001fb300@DataLoader_1fb300@fn_f428f7d4@@QAE_NTInventoryArg_1fb300@2@@Z @b904fbdd8c2a @w31563c817535
// STATUS: equivalent (tools/equiv.py level 3: 4505 inputs, branch coverage 6/6)
// FUN_001fb300 @ 0x001fb300
bool DataLoader_1fb300::FUN_001fb300(InventoryArg_1fb300 arg)
{
    struct Frame {
        char buf[0x40];
    } f;
    if (cur < end) {
        Inventory_1fb300 *inv = arg.inv;
        for (int i = cur; i < end; i++) {
            FUN_000964a0(f.buf, 0x40, "GameDataHandlerRaw%d", i);
            unsigned __int64 key = FUN_002672f0(f.buf, 0, 0);
            HandlerObj *h = inv->v3(new (arg.caster) content::LoadInventory::DynamicCaster<CDataHandlerObject>, key);
            if (h) {
                FUN_001fab00(h->f0c, h->f08);
                inv->v5(h);
            }
        }
    }
    cur = end;
    return true;
}

} // namespace fn_f428f7d4
