// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002474c0..0x00247680 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/records.h"
#define TREE_TU_BEGIN namespace fn_f882a82e {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f882a82e {} using namespace fn_f882a82e;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f882a82e {
extern "C" void FUN_00266eb0(int, int, int);
extern "C" void __cdecl FUN_00266f20(int, int);
struct V {
    void* a;
    int(__cdecl* b)(void*, int);
};
typedef int(__cdecl* Fn_247550)(void*, int, int);
struct T_247550 {
    void* x;
    void* y;
    Fn_247550 f;
};
struct TextBuffer {
    char storage[sizeof(OmType)];  // an om::Type (records.h)
    void *FUN_002584d0(void *, void *, unsigned int, unsigned int);
    void FUN_002580e0();
};
struct OutputSink {
    void *slot0;
    void *slot1;
    void (__cdecl *slot2)(OutputSink *, void *, const char *);
};
class CDisplayEffect {
  public:
    class DrawableText {
      public:
        virtual void* f1_00247680(char);
        virtual void f2();
        void* a;
        void* b;
        DrawableText(void* x, void* y);
    };
};
extern void* hulk_at_00429254;
struct Tmp_247610 {
    char pad[sizeof(OmType)];  // an om::Type (records.h)
    Tmp_247610* init_002584d0(void*, void*, unsigned, unsigned);
    void cleanup_002580e0();
};
struct Alloc_247610 {
    void*(__cdecl* f0)();
    void*(__cdecl* alloc)(Alloc_247610*, Tmp_247610*);
};


// 0x002474c0 FUN_002474c0 (23 B): matches/0x002474c0.cpp
// sym: _FUN_002474c0
// The om allocator's allocate slot (0x004cc200 +4): an instance of the type's size and alignment from heap 0
// (the volatile read keeps MSVC's load order).
extern "C" void FUN_002474c0(int unused, OmType* type) {
    int size = *(volatile int*)&type->body.size;
    FUN_00266eb0(0, size, type->body.align);
}


// 0x002474e0 FUN_002474e0 (16 B): matches/0x002474e0.cpp
// sym: _FUN_002474e0
extern "C" void __cdecl FUN_002474e0(int, int, int param3) {
    FUN_00266f20(0, param3);
}


// 0x002474f0 FUN_002474f0 (16 B): matches/0x002474f0.cpp
// sym: _FUN_002474f0
// data: g_ptr = DAT_004cc1fc
extern "C" void* __cdecl FUN_002474f0(void* value) {
    void* old = (*(void**)&DAT_004cc1fc);
    (*(void**)&DAT_004cc1fc) = value;
    return old;
}


// 0x00247530 FUN_00247530 (18 B): matches/0x00247530.cpp
// sym: _FUN_00247530
extern "C" hulk_intptr FUN_00247530(hulk_intptr x) {
    return (*(V**)&DAT_004cc1fc)->b((*(V**)&DAT_004cc1fc), x);
}


// 0x00247550 FUN_00247550 (23 B): matches/0x00247550.cpp
// sym: _FUN_00247550
extern "C" int FUN_00247550(hulk_intptr a, hulk_intptr b) {
    return (*(T_247550**)&DAT_004cc1fc)->f((*(T_247550**)&DAT_004cc1fc), a, b);
}


// 0x00247570 FUN_00247570 (71 B): equivalent/0x00247570.cpp
// sym: _FUN_00247570 @083d893685f9 @w19666263306d
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 2/2)
// FUN_00247570 @ 0x00247570
extern "C" void __cdecl FUN_00247570(const char *text) {
    if (text) {
        unsigned int length = ((const unsigned int *)text)[-1];
        TextBuffer buffer;
        void *result = buffer.FUN_002584d0(((char*)&DAT_004e5f88), ((char*)&DAT_004e5f90), ((const unsigned int *)text)[-2], length);
        OutputSink *sink = (*(OutputSink**)&DAT_004cc1fc);
        sink->slot2(sink, result, text - length);
        buffer.FUN_002580e0();
    }
}


// 0x002475c0 FUN_002475c0 (25 B): matches/0x002475c0.cpp
// sym: ??0DrawableText@CDisplayEffect@fn_f882a82e@@QAE@PAX0@Z
// Same code shape as 0x000ded90 (propagated; names are from that function)
CDisplayEffect::DrawableText::DrawableText(void* x, void* y) {
    a = x;
    b = y;
}


// 0x002475e0 FUN_002475e0 (7 B): matches/0x002475e0.cpp
// sym: ?FUN_002475e0@fn_f882a82e@@YIXPAX@Z
// Same code shape as 0x001b6820 (propagated; names are from that function)
void __fastcall FUN_002475e0(void* self) {
    *(void**)self = &hulk_at_00429254;
}


// 0x00247610 FUN_00247610 (98 B): matches/0x00247610.cpp
// sym: _FUN_00247610
// data: gAlloc_247610 = DAT_004cc1fc
extern "C" void* __cdecl FUN_00247610(int a, int b, unsigned size, unsigned align) {
    if (!(size > 0))
        return 0;
    if (align <= 8)
        align = 8;
    size += align;
    Tmp_247610 t;
    Tmp_247610* ptr = t.init_002584d0(((char*)&DAT_004e5f88), ((char*)&DAT_004e5f90), size, align);
    char* p = (char*)(*(Alloc_247610**)&DAT_004cc1fc)->alloc((*(Alloc_247610**)&DAT_004cc1fc), ptr);
    t.cleanup_002580e0();
    char* q = p + align;
    *(unsigned*)(q - 4) = align;
    *(unsigned*)(q - 8) = size;
    return q;
}

} // namespace fn_f882a82e
