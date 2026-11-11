// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0008ceb0..0x0008dbb0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "decls/address.h"
#include "decls/data/game/unknown.h"
#define TREE_TU_BEGIN namespace fn_fb593698 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fb593698 {} using namespace fn_fb593698;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_fb593698 {
class Heap_8d0a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(int* used, int a, int b, unsigned int* peak);
    virtual void v10();
    virtual int v11();
};
} // namespace fn_fb593698
class Gfx {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33(const char* text, int x, int y, unsigned int color);
};
namespace fn_fb593698 {
struct HeapEntry_8d0a0 {
    const char* name;
    int pad_04;
    int baseline;
};
class MemoryDisplay {
  public:
    void FUN_0008d0a0(bool dim);
    int pad_00;
    Heap_8d0a0* heaps[19];
};
extern void __cdecl FUN_0026b800(char* output, int zero, const char* input, int one, int delimiter, int capacity, int last);
extern bool __cdecl FUN_0008d880(const char*, const char*);


// 0x0008d0a0 FUN_0008d0a0 (574 B): equivalent/0x0008d0a0.cpp
// sym: ?FUN_0008d0a0@MemoryDisplay@fn_fb593698@@QAEX_N@Z @356f9bcf21e1 @w2c75123fe2ec
// STATUS: equivalent (tools/equiv.py level 3: 859 inputs, branch coverage 10/10)
// FUN_0008d0a0 @ 0x0008d0a0
void MemoryDisplay::FUN_0008d0a0(bool dim) {
    char text[0x80];
    DAT_0052c2a8->v33("Pool", 0x32, 0x32, 0xffff8000);
    DAT_0052c2a8->v33("Used", 0xf0, 0x32, 0xffff8000);
    DAT_0052c2a8->v33("Free", 0x15e, 0x32, 0xffff8000);
    DAT_0052c2a8->v33("High Watermark", 0x1cc, 0x32, 0xffff8000);
    unsigned int toggle = ~DAT_004dd77c & 0xff;
    unsigned int gray = ((((toggle | 0xffffff00) << 8) | toggle) << 8) | toggle;
    DAT_004dd77c = toggle;
    int y = 0x41;
    Heap_8d0a0** heap = heaps;
    for (HeapEntry_8d0a0* entry = ((HeapEntry_8d0a0*)&DAT_00400520); entry < (HeapEntry_8d0a0*)((char*)&DAT_00400604); ++entry, ++heap, y += 0xf) {
        if (*heap == 0)
            continue;
        int total = (*heap)->v11();
        int used;
        unsigned int peak;
        (*heap)->v9(&used, 0, 0, &peak);
        int usedBytes = total - used;
        int freeBytes = used - entry->baseline;
        unsigned int color = 0xffff8000;
        if (dim)
            color = gray;
        if (freeBytes < 0)
            color = 0xffff0000;
        DAT_0052c2a8->v33(entry->name, 0x32, y, color);
        sprintf(text, "%.2fk", usedBytes * 0.0009765625f);
        DAT_0052c2a8->v33(text, 0xf0, y, color);
        sprintf(text, "%.2fk", freeBytes * 0.0009765625f);
        DAT_0052c2a8->v33(text, 0x15e, y, color);
        sprintf(text, "%.2fk", peak * 0.0009765625f);
        DAT_0052c2a8->v33(text, 0x1cc, y, color);
    }
}


// 0x0008d910 FUN_0008d910 (221 B): equivalent/0x0008d910.cpp
// sym: _FUN_0008d910 @4a1e345dd3e9 @w224d110bdb54
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 12/12)
// FUN_0008d910 @ 0x0008d910
extern "C" bool __cdecl FUN_0008d910(const char* name)
{
    bool result = false;
    char buffer[256];
    if (name) {
        FUN_0026b800(buffer, 0, name, 1, '.', 256, 0);
        result = FUN_0008d880(buffer, ".rcf") ||
                 FUN_0008d880(buffer, ".RCF") ||
                 FUN_0008d880(buffer, "rcfs.txt") ||
                 FUN_0008d880(buffer, "dsstdfx.bin") ||
                 FUN_0008d880(buffer, "rsdeffects.bin");
    }
    return result;
}

} // namespace fn_fb593698
