// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00259d30..0x0025aa50 (kind game, layer engine, confidence high), dominant class audio::Mix
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_fee56a04 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fee56a04 {} using namespace fn_fee56a04;
#include "engine/audio.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_fee56a04 {
struct Allocator {
    char pad[1];
};
Allocator* __cdecl FUN_00241670();
extern "C" void* __cdecl FUN_00247530(Allocator* a);
extern "C" void __cdecl FUN_00247550(Allocator* a, void* p);
namespace audio {
class MixBuss {
public:
    MixBuss() : level(1.0f), gain(1.0f), parent(0), child(0), dirty(0) {}
    virtual void v0();
    char pad04[0x14 - 4];
    int key;            // 0x14
    float level;        // 0x18
    float gain;         // 0x1c
    int parent;         // 0x20
    int child;          // 0x24
    char dirty;         // 0x28
};
}
struct Key_25a7e0 {
    int value;
};
class MixRegistry {
public:
    char pad0[0x38];
    char table[1];      // 0x38
    audio::MixBuss* FUN_0025a7e0(Key_25a7e0* key);
};
extern "C" bool __cdecl FUN_0025a610(void* table, audio::MixBuss* buss, int* key);


// 0x0025a7e0 FUN_0025a7e0 (114 B): equivalent/0x0025a7e0.cpp
// sym: ?FUN_0025a7e0@MixRegistry@fn_fee56a04@@QAEPAVMixBuss@audio@2@PAUKey_25a7e0@2@@Z @ed8872547162 @wf5d8b11fc189
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 4/4)
// FUN_0025a7e0 @ 0x0025a7e0
// Creates a mix buss for the key and registers it; frees it again when registration fails.
audio::MixBuss* MixRegistry::FUN_0025a7e0(Key_25a7e0* key)
{
    void* mem = FUN_00247530(FUN_00241670());
    audio::MixBuss* buss = 0;
    if (mem != 0)
        buss = new (mem) audio::MixBuss();
    buss->key = key->value;
    if (FUN_0025a610(table, buss, &buss->key))
        return buss;
    FUN_00247550(FUN_00241670(), buss);
    return 0;
}

} // namespace fn_fee56a04
