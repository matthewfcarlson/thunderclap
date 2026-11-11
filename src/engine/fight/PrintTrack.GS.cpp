// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00238850..0x002393a0 (kind game, layer engine, confidence high), dominant class fight::PrintTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/fight.h"
#define TREE_TU_BEGIN namespace fn_f6c6e304 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f6c6e304 {} using namespace fn_f6c6e304;
#include "engine/fight.h"

// ---- declarations shared by the functions below
namespace fn_f6c6e304 {
typedef int (__cdecl *SinkFn)(int, int, const char*, int);
int __cdecl FUN_00267730(char* buf, int size, const char* fmt, char* args);


// 0x00238bb0 FUN_00238bb0 (135 B): matches/0x00238bb0.cpp
// sym: ?FUN_00238bb0@fn_f6c6e304@@YAHHHPBDZZ
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00238bb0 @ 0x00238bb0
int __cdecl FUN_00238bb0(int a1, int a2, const char* fmt, ...)
{
    struct Frame {
        char buf[0x400];
    } fr;
#if defined(HULK_PTR64)
    __builtin_va_list va;
    __builtin_va_start(va, fmt);
    FUN_00267730(fr.buf, 0x400, fmt, va);
#else
    FUN_00267730(fr.buf, 0x400, fmt, (char*)(&fmt + 1));
#endif
    if (!(*(SinkFn*)&DAT_004e5c30)) {
        return -1;
    }
    int result = (*(SinkFn*)&DAT_004e5c30)(a1, a2, fr.buf, DAT_004e5c34);
    return result;
}

} // namespace fn_f6c6e304
