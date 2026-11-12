// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x003287a0..0x00329430 (kind game, layer platform/xbox, confidence medium), dominant class pure3d::d3dVertexProgram
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/platform/xbox/pure3d.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f967e045 {
#define TREE_TU_END }
namespace fn_f967e045 {} using namespace fn_f967e045;
#include "platform/xbox/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f967e045 {
struct Item_3287a0 { virtual void s0(); virtual void s1(); virtual void s2(); virtual void enable(int); virtual void update(float,float,float,float,unsigned); };
struct Manager_3287a0 {
virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45(); virtual void s46(); virtual void s47(); virtual void s48(); virtual void s49();
virtual void s50(); virtual void s51(); virtual void s52(); virtual void s53(); virtual void s54(); virtual void s55(); virtual void s56(); virtual void s57(); virtual void s58(); virtual void s59();
virtual void s60(); virtual void s61(); virtual void s62(); virtual void s63(); virtual void s64(); virtual void s65(); virtual void s66(); virtual void s67(); virtual void s68(); virtual void s69();
virtual void s70(); virtual void s71(); virtual void s72(); virtual void s73(); virtual void s74(); virtual void s75(); virtual void s76(); virtual void s77(); virtual void s78(); virtual void s79();
virtual void s80(); virtual void s81(); virtual void s82(); virtual void s83(); virtual void s84(); virtual void s85(); virtual void s86(); virtual void s87(); virtual void s88(); virtual Item_3287a0* get(int);
};
// d3dContext's state cache (0x00328fc0 builds it: the context, its handle, then the reset 0x00328f10)
class Obj_328fc0 {
  public:
    pure3d::d3dContext* a;
    int b;
    void FUN_00328f10();
    Obj_328fc0* Target(pure3d::d3dContext*, int);
};
namespace D3D8 {
int __stdcall D3DDevice_CreateVertexShader(const unsigned int* decl, const void* program, unsigned int* handle, int usage);
}
extern "C" unsigned int __cdecl FUN_00329060(char *);
struct ShaderEntry {
    int unk0;
    unsigned int a;
    unsigned int flags;
    int c;
    int size;
    unsigned int handle;
};
struct ShaderGroup {
    unsigned int hash;
    const void* program;
    unsigned int count;
    ShaderEntry entries[32];
};
struct DeclFrame {
    char pad0[0x13];
    unsigned char b;
    unsigned int handle;
    unsigned int decl[63];
};
class ShaderCache_3290e0 {
  public:
    int pad0;
    unsigned int count;
    ShaderGroup groups[1];
    ShaderEntry* Get(const char* name, unsigned int a, unsigned int flags, int c);
};
extern "C" int HashName(const char*);
extern "C" void __cdecl FUN_00329000();
extern "C" void __stdcall FUN_00013420(void*, int, int, const float*);


// 0x003287a0 FUN_003287a0 (377 B): equivalent/0x003287a0.cpp
// sym: ?FUN_003287a0@fn_f967e045@@YAXXZ @9ce4b70416cd @w78a831676b8d
// STATUS: equivalent (tools/equiv.py level 3: 20066 inputs, branch coverage 17/20, incomplete)
// FUN_003287a0 @ 0x003287a0
void __cdecl FUN_003287a0() {
 Item_3287a0* item=(*(Manager_3287a0**)&DAT_00555b88)->get(0x103);
 if (!(*(int*)&DAT_00555b84)) item->enable(0);
 else {
 float scale=1.0f / (*(int*)&DAT_00555b84);
 item->enable(1);
 int r=(int)(__int64)(DAT_00555b80 * scale);
 int g=(int)(__int64)(DAT_00555b7c * scale);
 int b=(int)(__int64)(DAT_00555b78 * scale);
 if(r<0) r=0; else if(r>255) r=255;
 if(g<0) g=0; else if(g>255) g=255;
 if(b<0) b=0; else if(b>255) b=255;
 unsigned color=0xff000000u | (b<<16) | (g<<8) | r;
 float d=DAT_00555b70 * scale;
 float c=DAT_00555b74 * scale;
 float y=DAT_00555b6c * scale;
 float x=DAT_00555b68 * scale;
 item->update(x,y,c,d,color);
 }
 (*(int*)&DAT_00555b84)=0;
 DAT_00555b68=0; DAT_00555b6c=0; DAT_00555b70=0; DAT_00555b74=0; DAT_00555b78=0; DAT_00555b7c=0; DAT_00555b80=0;
}


// 0x00328be0 FUN_00328be0 (1 B): matches/0x00328be0.cpp
// sym: _FUN_00328be0
// Same code shape as 0x00025410 (propagated; names are from that function)
extern "C" void FUN_00328be0() {}

} // namespace fn_f967e045

// 0x00328bf0 FUN_00328bf0 (791 B): equivalent/0x00328bf0.cpp [wrapped: compile error C2668: 'fn_f967e045::D3D8::D3DDevice_SetTextureState_TexCoordIndex' : ambiguous call to overloaded function]
// sym: ?FUN_00328bf0@Material_328bf0@fn_00328bf0@@QAEXXZ @950c74b28049 @w38e2169208b0
namespace fn_00328bf0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_00328bf0 @ 0x00328bf0

typedef unsigned long DWORD;
namespace D3D8 {
void __stdcall D3DDevice_SetTexture(DWORD, DWORD);
void __stdcall D3DDevice_SetPalette(DWORD, DWORD);
void __stdcall D3DDevice_SetTextureState_TexCoordIndex(DWORD, DWORD);
void __fastcall D3DDevice_SetRenderState_Simple(DWORD method, DWORD value);
void __stdcall D3DDevice_SetRenderState_TextureFactor(DWORD);
void __stdcall D3DDevice_SetRenderState_NormalizeNormals(DWORD);
void __stdcall D3DDevice_SetPixelShader(DWORD);
void __stdcall D3DDevice_SetTextureState_BumpEnv(DWORD stage, DWORD type, DWORD value);
}
struct Texture {
};
struct TexModeEntry {
    int v;
    int pad[2];
};
struct StageRegs_328bf0 {
    int addr0, addr1, addr2;
    int mode0, mode1, mode2;
    char pad0[0x30 - 0x18];
    int c64, ca4, c84, c94, c74, cd4, cb4, cc4, ce4, cf4;
    char pad1[0x80 - 0x58];
};
extern volatile unsigned int DAT_0039db08;
extern char DAT_0039db1c[];
extern unsigned int DAT_0039dea8;
extern unsigned int DAT_0039deac;
extern unsigned int DAT_0039de18;
extern unsigned int DAT_0039ddfc;
extern unsigned int DAT_0039de08;
extern unsigned int DAT_0039de0c;
extern unsigned int DAT_0039de00;
extern unsigned int DAT_0039ddf8;
extern unsigned int DAT_0039de04;
// the d3dContext's state cache (owners::State_328f10's layout: 0x00328fc0 builds it, 0x00328f10 resets it)
struct Material_328bf0 {
    void* context;
    int handle;
    Texture* tex[4];
    char pad18[0x28 - 0x18];
    int addrMode[4];
    int texMode[4];
    int f48;
    unsigned char f4c;
    char pad4d[0x54 - 0x4d];
    int f54;
    int f58;
    unsigned char f5c;
    char pad5d[3];
    int f60;
    int a64[4];
    int a74[4];
    int a84[4];
    int a94[4];
    int aa4[4];
    int ab4[4];
    int ac4[4];
    int ad4[4];
    int ae4[4];
    int af4[4];
    unsigned char f104;
    char pad105[3];
    int f108;
    int f10c;
    char pad110[4];
    int f114;
    int f118;
    int f11c;
    int f120;
    void FUN_00328bf0();
};
void Material_328bf0::FUN_00328bf0() {
    StageRegs_328bf0* regs = (StageRegs_328bf0*)(DAT_0039db1c - 0xc);
    for (unsigned int i = 0; i < 4; i++) {
        if (tex[i]) {
            ((owners::Obj_326b00 *)(tex[i]))->FUN_00326b00((unsigned long)i);
        } else {
            D3D8::D3DDevice_SetTexture(i, 0);
            D3D8::D3DDevice_SetPalette(i, 0);
        }
        unsigned int bit = 1 << i;
        regs[i].mode1 = ((TexModeEntry*)&DAT_004d4e10)[texMode[i]].v;
        DAT_0039db08 |= bit;
        regs[i].mode0 = ((TexModeEntry*)((char*)&DAT_004d4e10 + 4))[texMode[i]].v;
        DAT_0039db08 |= bit;
        regs[i].mode2 = ((TexModeEntry*)((char*)&DAT_004d4e10 + 8))[texMode[i]].v;
        DAT_0039db08 |= bit;
        D3D8::D3DDevice_SetTextureState_TexCoordIndex(i, i);
        regs[i].addr0 = ((unsigned int*)&DAT_004d4efc)[addrMode[i]];
        DAT_0039db08 |= bit;
        regs[i].addr1 = ((unsigned int*)&DAT_004d4efc)[addrMode[i]];
        DAT_0039db08 |= bit;
        regs[i].addr2 = ((unsigned int*)&DAT_004d4efc)[addrMode[i]];
        DAT_0039db08 |= bit;
        regs[i].c84 = a84[i];
        DAT_0039db08 |= 0x800;
        regs[i].c64 = a64[i];
        DAT_0039db08 |= 0x800;
        regs[i].c94 = a94[i];
        DAT_0039db08 |= 0x800;
        regs[i].cb4 = ab4[i];
        DAT_0039db08 |= 0x800;
        regs[i].c74 = a74[i];
        DAT_0039db08 |= 0x800;
        regs[i].cc4 = ac4[i];
        DAT_0039db08 |= 0x800;
        regs[i].ca4 = aa4[i];
        DAT_0039db08 |= 0x800;
        regs[i].cd4 = ad4[i];
        DAT_0039db08 |= 0x800;
        regs[i].ce4 = ae4[i];
        DAT_0039db08 |= 0x800;
        regs[i].cf4 = af4[i];
        DAT_0039db08 |= 0x400;
    }
    DAT_0039db08 |= 0x1200;
    DAT_0039dea8 = f104;
    DAT_0039db08 |= 0x3000;
    DAT_0039deac = f104;
    unsigned int v = ((unsigned int*)&DAT_004d4f24)[f48];
    D3D8::D3DDevice_SetRenderState_Simple(0x4037c, v);
    DAT_0039de18 = v;
    v = f4c;
    D3D8::D3DDevice_SetRenderState_Simple(0x40304, v);
    DAT_0039ddfc = v;
    v = ((unsigned int*)&DAT_004d4ed0)[f54];
    D3D8::D3DDevice_SetRenderState_Simple(0x40344, v);
    DAT_0039de08 = v;
    v = ((unsigned int*)&DAT_004d4ed0)[f58];
    D3D8::D3DDevice_SetRenderState_Simple(0x40348, v);
    DAT_0039de0c = v;
    v = f5c;
    D3D8::D3DDevice_SetRenderState_Simple(0x40300, v);
    DAT_0039de00 = v;
    v = ((unsigned int*)&DAT_004d4f04)[f60];
    D3D8::D3DDevice_SetRenderState_Simple(0x4033c, v);
    DAT_0039ddf8 = v;
    D3D8::D3DDevice_SetRenderState_TextureFactor(f108);
    v = f10c;
    D3D8::D3DDevice_SetRenderState_Simple(0x40340, v);
    DAT_0039de04 = v;
    D3D8::D3DDevice_SetRenderState_NormalizeNormals(1);
    D3D8::D3DDevice_SetPixelShader(0);
    D3D8::D3DDevice_SetTextureState_BumpEnv(2, 0x16, f114);
    D3D8::D3DDevice_SetTextureState_BumpEnv(2, 0x17, f118);
    D3D8::D3DDevice_SetTextureState_BumpEnv(2, 0x19, f11c);
    D3D8::D3DDevice_SetTextureState_BumpEnv(2, 0x18, f120);
}
} // namespace fn_00328bf0


// 0x00328f10 FUN_00328f10 (171 B): equivalent/0x00328f10.cpp
// sym: ?FUN_00328f10@State_328f10@owners@@QAEXXZ @b548758758d4 @wc9a47089c2e5
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00328f10 @ 0x00328f10
void owners::State_328f10::FUN_00328f10() {
 for (unsigned i = 0; i < 4; ++i) {
  indices18[i] = i;
  values08[i] = 0;
  values38[i] = 0;
  values28[i] = 0;
  values74[i] = 1;
  values64[i] = 1;
  valuesb4[i] = 1;
  values84[i] = 1;
  valuesc4[i] = 2;
  values94[i] = 2;
  valuesd4[i] = 1;
  valuesa4[i] = 1;
  valuese4[i] = 1;
  valuesf4[i] = 0;
 }
 flag4c = 0;
 value58 = 0;
 flag5c = 0;
 flag105 = 0;
 flag104 = 0;
 value108 = 0;
 value10c = 0;
 value118 = 0;
 value11c = 0;
 enabled48 = 1;
 enabled54 = 1;
 mode60 = 5;
 enabled110 = 1;
 scale114 = 1.0f;
 scale120 = 1.0f;
 FUN_00328bf0();
}

namespace fn_f967e045 {

// 0x00328fc0 FUN_00328fc0 (29 B): matches/0x00328fc0.cpp
// sym: ?Target@Obj_328fc0@fn_f967e045@@QAEPAV12@PAVd3dContext@pure3d@@H@Z
Obj_328fc0* Obj_328fc0::Target(pure3d::d3dContext* p2, int p3) {
    a = p2;
    b = p3;
    FUN_00328f10();
    return this;
}

} // namespace fn_f967e045

// 0x00329000 FUN_00329000 (7 B): matches/0x00329000.cpp [wrapped: helper definitions (3 out-of-line function bodies)]
// sym: ??1d3dVertexProgram@fn_00329000@@UAE@XZ
namespace fn_00329000 {
class d3dVertexProgram {
  public:
    virtual void hulk_slot_Fn(); void Fn();
    virtual ~d3dVertexProgram();
    d3dVertexProgram();
};

void d3dVertexProgram::Fn() {}

d3dVertexProgram::~d3dVertexProgram() {}

d3dVertexProgram::d3dVertexProgram() {
    Fn();
}
} // namespace fn_00329000


// 0x00329010 pure3d::d3dVertexProgram::vfunc_0 (3 B): matches/0x00329010.cpp
// sym: ?vfunc_0@d3dVertexProgram@pure3d@@UAEXHH@Z
// Same code shape as 0x00306fc0 (propagated; names are from that function)
void pure3d::d3dVertexProgram::vfunc_0(int a, int b) {}

namespace fn_f967e045 {

// 0x00329060 FUN_00329060 (52 B): matches/0x00329060.cpp
// sym: _FUN_00329060
extern "C" unsigned int FUN_00329060(char* s) {
    unsigned int h = 0;
    char c = *s;
    while (c != 0) {
        h = h * 16 + (int)c;
        s++;
        unsigned int t = h & 0xf0000000;
        if (t) {
            unsigned int u = t ^ (t >> 24);
            h ^= u;
        }
        c = *s;
    }
    return h;
}

} // namespace fn_f967e045

// 0x003290a0 FUN_003290a0 (9 B): matches/0x003290a0.cpp [wrapped: conflict: DAT_00433774]
// sym: @FUN_003290a0@4
namespace fn_003290a0 {
extern "C++" { extern char hulk_at_00433770[]; }
// (x64t5) the vftable pointer is the game's address 0x00433774 itself (the vftable at 0x00433770, one slot in): was a
// local one-word array holding that address, which the Wine link bound to the game's word by address (vptr then
// 0x00433774) but which natively made vptr point at the local array
struct Obj_3290a0 {
    void* vptr;
};
extern "C" void* __fastcall FUN_003290a0(Obj_3290a0* self) {
    self->vptr = hulk_at_00433770 + 0x4;
    return self;
}
} // namespace fn_003290a0

namespace fn_f967e045 {

// 0x003290e0 FUN_003290e0 (572 B): equivalent/0x003290e0.cpp
// sym: ?Get@ShaderCache_3290e0@fn_f967e045@@QAEPAUShaderEntry@2@PBDIIH@Z @134c99deb6b4 @wa18e7278dc4a
// STATUS: equivalent (tools/equiv.py level 3: 42 inputs, branch coverage 43/44, incomplete)
// FUN_003290e0 @ 0x003290e0
ShaderEntry* ShaderCache_3290e0::Get(const char* name, unsigned int a, unsigned int flags, int c) {
    DeclFrame F;
    unsigned int hash = FUN_00329060((char *)(const char *)name);
    F.b = (unsigned char)(c & 1);
    ShaderGroup* g = &groups[0];
    for (unsigned int i = 0; i < count; i++) {
        if (groups[i].hash == hash) {
            g = &groups[i];
            break;
        }
    }
    for (unsigned int k = 0; k < g->count; k++) {
        ShaderEntry* e = &g->entries[k];
        if (e->a == a && e->flags == flags && e->c == c)
            return e;
    }
    ShaderEntry* e = &g->entries[g->count];
    g->count++;
    int n = 2;
    int size = 0xc;
    F.decl[0] = 0x20000000;
    F.decl[1] = 0x40320000;
    if (flags & 0x100) {
        n = 3;
        if (F.b) {
            F.decl[2] = 0x40160001;
            size = 0x10;
        } else {
            F.decl[2] = 0x40320001;
            size = 0x18;
        }
    }
    if (flags & 0x80) {
        F.decl[n++] = 0x4040000f;
        size += 4;
    }
    if (flags & 0x10) {
        if (F.b) {
            F.decl[n++] = 0x40160002;
            size += 4;
        } else {
            F.decl[n++] = 0x40320002;
            size += 0xc;
        }
    }
    if (flags & 0x20) {
        F.decl[n++] = 0x40400003;
        size += 4;
    }
    if (flags & 0x4000) {
        F.decl[n++] = 0x40400003;
        F.decl[n++] = 0x40400004;
        size += 8;
    }
    if (flags & 0x40) {
        F.decl[n++] = 0x40400004;
        size += 4;
    }
    unsigned int cnt = flags & 0xf;
    if (cnt) {
        size += cnt * 8;
        for (unsigned int i = 0; i < cnt; i++)
            F.decl[n++] = (i + 9) | 0x40220000;
    }
    if (flags & 0x200) {
        F.decl[n++] = 0x4012000e;
        size += 4;
    }
    if (flags & 0x400) {
        F.decl[n++] = 0x4012000d;
        size += 4;
    }
    if (flags & 0x800) {
        F.decl[n++] = 0x40320006;
        size += 0xc;
    }
    if (flags & 0x1000) {
        F.decl[n++] = 0x4032000f;
        size += 0xc;
    }
    F.decl[n] = 0xffffffff;
    F.handle = 0;
    int hr = D3D8::D3DDevice_CreateVertexShader(F.decl, g->program, &F.handle, 0);
    FUN_0031c230(hr);
    e->handle = F.handle;
    e->flags = flags;
    e->size = size;
    e->a = a;
    e->c = c;
    return e;
}

} // namespace fn_f967e045

// 0x00329320 FUN_00329320 (151 B): matches/0x00329320.cpp
// sym: ?FUN_00329320@Registry_329320@owners@@QAEXPBDI@Z
void owners::Registry_329320::FUN_00329320(const char* name, unsigned int value) {
    int hash = HashName(name);
    unsigned int i = 0;
    while (i < count) {
        if (*(int*)((char*)this + 8 + i * 0x30c) == hash)
            return;
        ++i;
    }
    unsigned int h = 0;
    const char* p = name;
    while (*p) {
        h = h * 16 + (int)*p;
        ++p;
        unsigned int x = h & 0xf0000000;
        if (x)
            h ^= (x >> 24) ^ x;
    }
    *(unsigned int*)((char*)this + 8 + count * 0x30c) = h;
    *(unsigned int*)((char*)this + 12 + count * 0x30c) = value;
    *(unsigned int*)((char*)this + 16 + count * 0x30c) = 0;
    ++count;
}


// 0x00329400 FUN_00329400 (43 B): matches/0x00329400.cpp
// sym: ?FUN_00329400@Obj_329400@owners@@QAEXXZ
void owners::Obj_329400::FUN_00329400() {
    char* p = ((char*)this) + 0x3d04;
    for (int i = 0x14; i != 0; --i) {
        p -= 0x30c;
        FUN_00013420((void*)p, 0x18, 0x20, (const float*)((hulk_intptr)(void (__cdecl*)())&FUN_00329000));
    }
}

