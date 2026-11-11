// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002ddfb0..0x002de230 (kind game, layer engine, confidence medium), dominant class pure3d::DXTNHandler
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f10fa4c6 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f10fa4c6 {} using namespace fn_f10fa4c6;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f10fa4c6 {
struct Stream {
    char pad00[0xf];
    unsigned char flag;       // 0x0f
};
class Texture {
public:
    virtual char v0(int width, int height, int levels, int a, int b);
    virtual void v1();
    virtual void v2();
    virtual void v3(void *data, int size);
    virtual void *v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(int format);
    virtual void v10();
};
struct DdsHeader {
    unsigned int size;           // 0x00
    unsigned int flags;          // 0x04
    unsigned int height;         // 0x08
    unsigned int width;          // 0x0c
    unsigned int pitchOrLinear;  // 0x10
    unsigned int depth;          // 0x14
    unsigned int mipCount;       // 0x18
    unsigned int reserved[11];   // 0x1c
    unsigned int pfSize;         // 0x48
    unsigned int pfFlags;        // 0x4c
    unsigned int fourCC;         // 0x50
    unsigned int bitCount;       // 0x54
    unsigned int masks[4];       // 0x58
    unsigned int caps[5];        // 0x68
};
struct DdsFile {
    unsigned int magic;
    DdsHeader header;
};
extern "C" void *FUN_00266e00(int count, unsigned int size);
extern "C" void FUN_00267090(void *p);
typedef unsigned int u32_2de210;
extern "C" void __cdecl FUN_002de030(void *, void *);

} // namespace fn_f10fa4c6

// 0x002ddfb0 pure3d::DXTNHandler::vfunc_8 (24 B): matches/0x002ddfb0.cpp
// sym: ?vfunc_8@DXTNHandler@pure3d@@UAE_NH@Z
bool pure3d::DXTNHandler::vfunc_8(int x) {
    if (x < 5 || x > 10)
        return (bool)(0);
    return (bool)(1);
}

namespace fn_f10fa4c6 {

// 0x002de030 FUN_002de030 (460 B): equivalent/0x002de030.cpp
// sym: _FUN_002de030
// STATUS: equivalent (tools/equiv.py level 3: 3092 inputs, branch coverage 35/35)
// FUN_002de030 @ 0x002de030
extern "C" void FUN_002de030(void *s, void *tex)
{
    DdsFile f;
    ((char)((owners::X_2647e0 *)(((Stream *)s)))->FUN_002647e0((hulk_intptr)(&f.magic), (hulk_intptr)1, 4, (hulk_intptr)1));
    if (f.magic == 0x44445320)
        ((Stream *)s)->flag = (((Stream *)s)->flag == 0);
    ((char)((owners::X_2647e0 *)(((Stream *)s)))->FUN_002647e0((hulk_intptr)(&f.header), (hulk_intptr)0x1f, 4, (hulk_intptr)1));

    int format;
    switch (f.header.fourCC) {
    case 0x31545844: format = 4; break;   // DXT1
    case 0x32545844: format = 5; break;   // DXT2
    case 0x33545844: format = 6; break;   // DXT3
    case 0x34545844: format = 7; break;   // DXT4
    case 0x35545844: format = 8; break;   // DXT5
    default:
        return;
    }

    ((Texture *)tex)->v9(format);
    if (!((Texture *)tex)->v0(f.header.width, f.header.height, 2, 0, 0))
        return;

    if (f.header.flags & 0x80000) {
        void *dst = ((Texture *)tex)->v4();
        if (dst == 0)
            return;
        ((char)((owners::X_2647e0 *)(((Stream *)s)))->FUN_002647e0((hulk_intptr)dst, (hulk_intptr)(f.header.pitchOrLinear), 1, (hulk_intptr)1));
        ((Texture *)tex)->v10();
        return;
    }

    unsigned int rowBytes = (f.header.bitCount * f.header.width) >> 3;
    char *buf = (char *)FUN_00266e00(1, f.header.pitchOrLinear * f.header.height);
    if (buf == 0)
        return;
    char *row = buf;
    for (unsigned int y = 0; y < f.header.height; y++) {
        ((char)((owners::X_2647e0 *)(((Stream *)s)))->FUN_002647e0((hulk_intptr)row, (hulk_intptr)rowBytes, 1, (hulk_intptr)1));
        row += f.header.pitchOrLinear;
    }
    ((Texture *)tex)->v3(buf, f.header.pitchOrLinear * f.header.height);
    FUN_00267090(buf);
    ((Texture *)tex)->v10();
}

} // namespace fn_f10fa4c6

// 0x002de210 pure3d::DXTNHandler::vfunc_9 (21 B): matches/0x002de210.cpp
// sym: ?vfunc_9@DXTNHandler@pure3d@@UAEXHH@Z
// Same code shape as 0x00267230 (propagated; names are from that function)
void pure3d::DXTNHandler::vfunc_9(hulk_intptr __p0, hulk_intptr __p1) { u32_2de210 a = (u32_2de210)__p0; u32_2de210 b = (u32_2de210)__p1;

    FUN_002de030((void *)(hulk_uintptr)(unsigned int)a, (void *)(hulk_uintptr)(unsigned int)b);
}

