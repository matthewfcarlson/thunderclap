// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00328250..0x003287a0 (kind game, layer platform/xbox, confidence high), dominant class pure3d::d3dFBEffectsShader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/platform/xbox/pure3d.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fb517155 {
#define TREE_TU_END }
namespace fn_fb517155 {} using namespace fn_fb517155;
#include "platform/xbox/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_fb517155 {
struct Vertex_328270 {
    float x;
    float y;
    int color;
};
struct Batch_328270 {
    char pad_00[8];
    Vertex_328270* vertex;
    char pad_0c[4];
    int* extra;
    void FUN_0008ef00();
};
struct GlyphInfo {
    short offset;
    unsigned char numPoints;
    unsigned char numVerts;
};
class Renderer_328270 {
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
    virtual Batch_328270* v30(int a, int b, int c, int count, int d);
    virtual void v31(Batch_328270* batch);
};
class TextDrawer {
  public:
    Renderer_328270* renderer;
    void FUN_00328270(const char* text, int x, int y, int color, int extra);
};
class pddiObject_328520 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_328520 : public pddiObject_328520 {};
class pddiBaseShader_328520 : public pddiShader_328520 {
  public:
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual int UsesLayeredTexture();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc19();
    virtual void vfunc20();
};
class d3dShader_328520 : public pddiBaseShader_328520 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
} // namespace fn_fb517155
namespace pure3d {
class pddiObject_328540 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};
}
namespace pure3d {
class pddiShader_328540 {
  public:
};
}
namespace pure3d {
class pddiBaseShader_328540 : public pddiShader_328540 {
  public:
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_15();
    virtual void vfunc_19();
    virtual void vfunc_20();
};
}
namespace pure3d {
class d3dShader_328540 : public pddiBaseShader_328540 {
  public:
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
};
}
namespace fn_fb517155 {
class Obj_328560 {
  public:
    char pad[0x94];
    unsigned char flag;
    void Set(void* p);
};
class Obj_328580 {
  public:
    char pad[0x80];
    int value;
    void Set(int v);
};
class Obj_328590 {
  public:
    char pad[0x84];
    void* mPtr;
    void Set(void* p);
};
class Obj_3285a0 {
  public:
    char pad[0x88];
    int value;
    void Set(int x);
};
class Obj_3285b0 {
  public:
    char pad[0x8c];
    int value;
    void Set(int x);
};
class X_3285c0 {
  public:
    char pad[0x90];
    int value;
    void Set(int v);
};
typedef unsigned int u32_328690;
extern void* d3dShader_328770_vftable[];
class d3dShader_328770 {
  public:
    void Destroy(); // FUN_00236d60, __thiscall, this in ecx
};
class d3dFBEffectsShader_328770 : public d3dShader_328770 {
  public:
    d3dFBEffectsShader_328770* vfunc_5(signed char flags);
};

} // namespace fn_fb517155

// 0x00328250 FUN_00328250 (11 B): matches/0x00328250.cpp
// sym: ?FUN_00328250@C_328250@owners@@QAEPAU12@H@Z
owners::C_328250* owners::C_328250::FUN_00328250(hulk_intptr x) {
    value = ((int)x);
    return this;
}

namespace fn_fb517155 {

// 0x00328260 FUN_00328260 (1 B): matches/0x00328260.cpp
// sym: _FUN_00328260
// Same code shape as 0x00025410 (propagated; names are from that function)
extern "C" void FUN_00328260() {}


// 0x00328270 FUN_00328270 (621 B): equivalent/0x00328270.cpp
// sym: ?FUN_00328270@TextDrawer@fn_fb517155@@QAEXPBDHHHH@Z @532ba1f59000 @wb23598068305
// STATUS: equivalent (tools/equiv.py level 3: 4328 inputs, branch coverage 30/30)
// FUN_00328270 @ 0x00328270
void TextDrawer::FUN_00328270(const char* text, int px, int py, int color, int extra) {
    float t0 = DAT_004d4cd4 * 10.0f;
    float lineAdvance = DAT_004d4cd4 * 5.0f + t0;
    float halfX = DAT_004d4cd0 * 0.5f;
    float halfY = DAT_004d4cd4 * 0.5f;
    hulk_freg x = (float)px; // the tab path keeps the exact integer in the register, the glyph path stores a float
    float xStart = x;
    float y = (float)py * DAT_004d4cd4 + t0;
    int count = 0;
    for (const char* s = text; *s != 0; ++s) {
        unsigned char c = (unsigned char)*s;
        if (c >= 0x20 && c <= 0x7f)
            count += ((GlyphInfo*)&DAT_004d4ad0)[c].numVerts;
    }
    Batch_328270* batch = 0;
    if (count != 0)
        batch = renderer->v30(0, 2, 0x2020, count, 0);
    for (const char* p = text; *p != 0; ++p) {
        unsigned char c = (unsigned char)*p;
        if (c == '\n') {
            x = xStart;
            y = y + lineAdvance;
        } else if (c == '\t') {
            x = ((int)(__int64)x / 40 + 1) * 40; // _ftol: low word of the 64-bit conversion; not rounded to float
        } else if (c >= 0x20 && c <= 0x7f) {
            const GlyphInfo& info = ((GlyphInfo*)&DAT_004d4ad0)[c];
            signed char* g = &((signed char*)&DAT_004d4120)[info.offset * 2];
            int width = g[0];
            if (width < 0)
                width = -width;
            // baseX adds the unrounded sum; the stored (rounded) advance is read back later
            hulk_freg advanceReg = (float)width * halfX + 0.5f;
            float advance = (float)advanceReg;
            float baseX = x + advanceReg;
            for (int i = 1; i < (int)info.numPoints - 1; ++i) {
                if ((unsigned char)g[i * 2 + 2] == 0xce) {
                    ++i;
                } else {
                    for (int k = 0; k < 2; ++k) {
                        Vertex_328270* v = batch->vertex;
                        v->color = color;
                        v->x = (float)g[(i + k) * 2] * halfX + baseX;
                        v->y = (float)g[(i + k) * 2 + 1] * halfY + y;
                        *batch->extra = extra;
                        batch->FUN_0008ef00();
                    }
                }
            }
            x = baseX + advance; // stays unrounded in the x87 register until the next glyph's baseX store
        }
    }
    if (count != 0)
        renderer->v31(batch);
}


// 0x00328510 pure3d::d3dFBEffectsShader::vfunc_4 (6 B): matches/0x00328510.cpp
// sym: ?FUN_00328510@fn_fb517155@@YAHXZ
// Same code shape as 0x00085cd0 (propagated); reads 0x004d4ce8, a pointer item
hulk_intptr FUN_00328510(void) {
    return *(hulk_intptr*)&DAT_004d4ce8;
}

} // namespace fn_fb517155

// 0x00328520 pure3d::d3dFBEffectsShader::vfunc_11 (6 B): matches/0x00328520.cpp
// sym: ?vfunc_11@d3dFBEffectsShader@pure3d@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int pure3d::d3dFBEffectsShader::vfunc_11() {
    return 1;
}


// 0x00328530 pure3d::d3dFBEffectsShader::vfunc_14 (3 B): matches/0x00328530.cpp
// sym: ?vfunc_14@d3dFBEffectsShader@pure3d@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void pure3d::d3dFBEffectsShader::vfunc_14(int a) {
    (void)a;
}


// 0x00328540 pure3d::d3dFBEffectsShader::vfunc_12 (1 B): matches/0x00328540.cpp
// sym: ?vfunc_12@d3dFBEffectsShader@pure3d@@UAEXXZ
 // namespace pure3d
void pure3d::d3dFBEffectsShader::vfunc_12() {
    return;
}

namespace fn_fb517155 {

// 0x00328550 pure3d::d3dFBEffectsShader::vfunc_13 (1 B): matches/0x00328550.cpp
// sym: ?FUN_00328550@fn_fb517155@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_00328550() {}


// 0x00328560 FUN_00328560 (18 B): matches/0x00328560.cpp
// sym: ?Set@Obj_328560@fn_fb517155@@QAEXPAX@Z
void Obj_328560::Set(void* p) {
    flag = (p != 0);
}


// 0x00328580 FUN_00328580 (13 B): matches/0x00328580.cpp
// sym: ?Set@Obj_328580@fn_fb517155@@QAEXH@Z
void Obj_328580::Set(int v) {
    value = v;
}


// 0x00328590 FUN_00328590 (13 B): matches/0x00328590.cpp
// sym: ?Set@Obj_328590@fn_fb517155@@QAEXPAX@Z
void Obj_328590::Set(void* p) {
    mPtr = p;
}


// 0x003285a0 FUN_003285a0 (13 B): matches/0x003285a0.cpp
// sym: ?Set@Obj_3285a0@fn_fb517155@@QAEXH@Z
void Obj_3285a0::Set(int x) {
    value = x;
}


// 0x003285b0 FUN_003285b0 (13 B): matches/0x003285b0.cpp
// sym: ?Set@Obj_3285b0@fn_fb517155@@QAEXH@Z
void Obj_3285b0::Set(int x) {
    value = x;
}


// 0x003285c0 FUN_003285c0 (13 B): matches/0x003285c0.cpp
// sym: ?Set@X_3285c0@fn_fb517155@@QAEXH@Z
void X_3285c0::Set(int v) {
    value = v;
}

} // namespace fn_fb517155

// 0x003285d0 FUN_003285d0 (183 B): equivalent/0x003285d0.cpp
// sym: ?FUN_003285d0@AccumulatorSource_3285d0@owners@@QAEXI@Z @e3444f9ec9cd @we5f3b2b1d8c9
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_003285d0 @ 0x003285d0
void owners::AccumulatorSource_3285d0::FUN_003285d0(unsigned int unused) {
    if (enabled) {
        ++DAT_00555b84;
        DAT_00555b68 = DAT_00555b68 + x;
        DAT_00555b6c = DAT_00555b6c + y;
        DAT_00555b70 = DAT_00555b70 + z;
        DAT_00555b74 = DAT_00555b74 + w;
        DAT_00555b78 = float(blue) + DAT_00555b78;
        DAT_00555b7c = float(green) + DAT_00555b7c;
        DAT_00555b80 = float(red) + DAT_00555b80;
    }
}

namespace fn_fb517155 {

// 0x00328690 FUN_00328690 (10 B): matches/0x00328690.cpp
// sym: _FUN_00328690
// Same code shape as 0x001d0430 (propagated; names are from that function)
// data: gValue_328690 = DAT_00555b88
extern "C" void FUN_00328690(u32_328690 value) {
    (*(u32_328690*)&DAT_00555b88) = value;
}

} // namespace fn_fb517155

// 0x003286b0 pure3d::d3dShader::vfunc_22 (3 B): matches/0x003286b0.cpp
// sym: ?vfunc_22@d3dShader@pure3d@@UAE_NXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
bool pure3d::d3dShader::vfunc_22() {
    return (bool)(0);
}

namespace fn_fb517155 {

// 0x003286c0 pure3d::d3dShader::vfunc_23 (6 B): matches/0x003286c0.cpp
// sym: _FUN_003286c0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_003286c0() {
    return &(*(int*)&DAT_003f335c);
}


// 0x003286d0 pure3d::d3dShader::vfunc_24 (1 B): matches/0x003286d0.cpp
// sym: ?FUN_003286d0@fn_fb517155@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_003286d0() {}


// 0x003286e0 pure3d::d3dFBEffectsShader::vfunc_18 (6 B): matches/0x003286e0.cpp
// sym: _FUN_003286e0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_003286e0() {
    return &(*(int*)&DAT_004d4d78);
}


// 0x003286f0 pure3d::d3dFBEffectsShader::vfunc_17 (6 B): matches/0x003286f0.cpp
// sym: _FUN_003286f0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_003286f0() {
    return &(*(int*)&DAT_004d4d00);
}


// 0x00328700 pure3d::d3dFBEffectsShader::vfunc_16 (6 B): matches/0x00328700.cpp
// sym: _FUN_00328700
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00328700() {
    return &(*(int*)&DAT_004d4da8);
}

} // namespace fn_fb517155

// 0x00328720 FUN_00328720 (71 B): equivalent/0x00328720.cpp [wrapped: conflict: pure3d::d3dFBEffectsShader]
// sym: ??0d3dFBEffectsShader@pure3d@fn_00328720@@QAE@I@Z @07fdace754f2 @w13cf1ea960c7
namespace fn_00328720 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00328720 @ 0x00328720
namespace pure3d {
struct Base_328720 {
    virtual void slot0();
    char padding[0x7c];
    Base_328720(unsigned int value);
};
struct d3dFBEffectsShader : Base_328720 {
    unsigned int field80;
    unsigned int field84;
    float field88;
    unsigned int field8c;
    unsigned int field90;
    unsigned char field94;
    virtual void slot0();
    d3dFBEffectsShader(unsigned int value);
};
}
// Base constructor binds to FUN_00333520
pure3d::d3dFBEffectsShader::d3dFBEffectsShader(unsigned int value) : Base_328720(value) {
    field80 = 0;
    field84 = 0;
    field8c = 0;
    field88 = 0.5f;
    field90 = 0xffffffff;
    field94 = 0;
}
} // namespace fn_00328720

namespace fn_fb517155 {

// 0x00328770 pure3d::d3dFBEffectsShader::vfunc_3 (36 B): matches/0x00328770.cpp
// sym: ?vfunc_5@d3dFBEffectsShader_328770@fn_fb517155@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
d3dFBEffectsShader_328770* d3dFBEffectsShader_328770::vfunc_5(signed char flags) {
    *(void***)this = d3dShader_328770_vftable;
    Destroy();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_fb517155
