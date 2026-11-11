// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001f6bc0..0x001f76c0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#define TREE_TU_BEGIN namespace fn_f77ae7b3 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f77ae7b3 {} using namespace fn_f77ae7b3;
#include "game/hulkfight.h"

// ---- declarations shared by the functions below
extern "C" int __cdecl _sprintf(char *buf, const char *fmt, ...);
namespace fn_f77ae7b3 {
struct Vec3_1f6cd0 { int x, y, z; };
struct Source_1f6cd0 {
    char pad0[0x16];
    unsigned short bits;
};
struct HitInfo_1f6cd0 {
    int f0;
    char pad[0x2b8 - 4];
    void FUN_001d1630();
};
struct Library_1f6cd0 {
    int FUN_001d3b00(const char *name, HitInfo_1f6cd0 info);
};
extern "C" Library_1f6cd0 *__cdecl FUN_001d4c90();
struct Frame_1f6cd0 {
    char name[0x80];
    HitInfo_1f6cd0 info;
};
class Reaction_1f6cd0 {
public:
    char pad0[0x1c];
    Source_1f6cd0 *source;     // 0x1c
    int arg20;          // 0x20
    Vec3_1f6cd0 v24;           // 0x24
    Vec3_1f6cd0 v30;           // 0x30
    Vec3_1f6cd0 v3c;           // 0x3c
    int arg48;          // 0x48
    char pad4c[0x58 - 0x4c];
    int arg58;
    int arg5c;
    void FUN_001f6cd0(Source_1f6cd0 *src, hulk_intptr a1, const Vec3_1f6cd0 *a2, const Vec3_1f6cd0 *a3, const Vec3_1f6cd0 *a4,
                      int a5, int a6, int a7, const char **outName, int a9);
};


// 0x001f6cd0 FUN_001f6cd0 (392 B): equivalent/0x001f6cd0.cpp
// sym: ?FUN_001f6cd0@Reaction_1f6cd0@fn_f77ae7b3@@QAEXPAUSource_1f6cd0@2@HPBUVec3_1f6cd0@2@11HHHPAPBDH@Z @5dca925bfba3 @w0e387c638af8
// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 8/8)
// FUN_001f6cd0 @ 0x001f6cd0
void Reaction_1f6cd0::FUN_001f6cd0(Source_1f6cd0 *src, hulk_intptr a1, const Vec3_1f6cd0 *a2, const Vec3_1f6cd0 *a3, const Vec3_1f6cd0 *a4,
                            int a5, int a6, int a7, const char **outName, int a9)
{
    Frame_1f6cd0 f;
    unsigned short kind = (src->bits >> 5) & 0x1f;
    if (kind < 0x13) {
        if (outName)
            *outName = ((const char**)&DAT_004c8098)[kind];
        if (kind != 0x12) {
            f.info.FUN_001d1630();
            arg20 = a1;
            source = src;
            v24 = *a2;
            v30 = *a3;
            v3c = *a4;
            arg48 = a1;
            arg58 = a6;
            arg5c = a7;
            f.info.f0 = 0;
            _sprintf(f.name, "Damage_%s_%s", ((const char**)&DAT_004c8070)[a5], ((const char**)&DAT_004c8098)[kind]);
            if (!FUN_001d4c90()->FUN_001d3b00(f.name, f.info)) {
                _sprintf(f.name, "Damage_%s_Generic", ((const char**)&DAT_004c8070)[a5]);
                FUN_001d4c90()->FUN_001d3b00(f.name, f.info);
            }
        }
    }
}

} // namespace fn_f77ae7b3
