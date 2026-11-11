// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00338d90..0x0033a080 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "decls/data/game/global.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_fe093b2d {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fe093b2d {} using namespace fn_fe093b2d;
#include "engine/lua.h"

// ---- declarations shared by the functions below
namespace fn_fe093b2d {
extern "C" int __cdecl FUN_00213fc0(LuaVMState* L, int level, LuaVMDebug* ar);
extern "C" void __cdecl FUN_00213380(LuaVMState* L, const char* s, unsigned int len);
extern "C" const char* __cdecl FUN_00213470(LuaVMState* L, const char* fmt, ...);
extern "C" int __cdecl FUN_00214bd0(LuaVMState* L, const char* what, LuaVMDebug* ar);
extern "C" LuaVMFile DAT_004d99f0;
extern "C" int __cdecl FUN_00212d70(LuaVMState *L);
extern "C" void __cdecl FUN_00212d80(LuaVMState *L, int idx);
extern "C" void __cdecl FUN_00212de0(LuaVMState *L, int idx);
extern "C" const char *__cdecl FUN_00213190(LuaVMState *L, int idx);
extern "C" int __cdecl FUN_00213b20(LuaVMState *L, LuaVMReader reader, void *data, const char *chunkname);
extern "C" const char *__cdecl FUN_00339770(LuaVMState *L, void *ud, unsigned int *size);
extern "C" int __cdecl FUN_003397c0(LuaVMState *L, int fnameindex);
extern "C" LuaVMFile *__cdecl FUN_003465b3(const char *name, const char *mode);
} // namespace fn_fe093b2d
extern "C" int __cdecl _getc(LuaVMFile *f);
extern "C" int __cdecl _ungetc(int c, LuaVMFile *f);
extern "C" int __cdecl _fclose(LuaVMFile *f);
namespace fn_fe093b2d {
extern "C" int __cdecl FUN_00338e20(LuaVMState* L, const char* fmt, ...);


// 0x00338d90 FUN_00338d90 (131 B): matches/0x00338d90.cpp
// sym: _FUN_00338d90
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00338d90 @ 0x00338d90
// Lua 5.0 luaL_where: pushes "source:line: " for the given call level, or "".
extern "C" void __cdecl FUN_00338d90(LuaVMState* L, int level)
{
    struct Frame {
        LuaVMDebug ar;
    } f;

    if (FUN_00213fc0(L, level, &f.ar)) {
        FUN_00214bd0(L, "Sl", &f.ar);
        if (f.ar.currentline > 0) {
            FUN_00213470(L, "%s:%d: ", f.ar.short_src, f.ar.currentline);
            return;
        }
    }
    FUN_00213380(L, ((const char*)&DAT_003f335c), 0);
}


// 0x00339800 FUN_00339800 (561 B): equivalent/0x00339800.cpp
// sym: _FUN_00339800
// STATUS: equivalent (tools/equiv.py level 3: 3033 inputs, branch coverage 24/24)
// FUN_00339800 @ 0x00339800
// equiv-conv: FUN_003397c0 edi ebx
// Lua 5.0 luaL_loadfile
extern "C" int __cdecl FUN_00339800(LuaVMState *L, const char *filename)
{
    LuaVMLoadF lf;
    int status;
    int readstatus;
    int c;
    int fnameindex = FUN_00212d70(L) + 1;

    lf.extraline = 0;
    if (filename == 0) {
        FUN_00213380(L, "=stdin", 6);
        lf.f = &DAT_004d99f0;
    } else {
        FUN_00213470(L, "@%s", filename);
        lf.f = FUN_003465b3(filename, "r");
        if (lf.f == 0) {
            const char *fname = FUN_00213190(L, fnameindex) + 1;
            const char *serr = FUN_00347b53(*FUN_00347ba4());
            FUN_00213470(L, "cannot read %s: %s", fname, serr);
            FUN_00212de0(L, fnameindex);
            return 2;
        }
    }
    c = _getc(lf.f);
    if (c == '#') {
        lf.extraline = 1;
        while ((c = _getc(lf.f)) != -1 && c != '\n') {
        }
        if (c == '\n') {
            c = _getc(lf.f);
        }
    }
    if (c == 0x1b && lf.f != &DAT_004d99f0) {
        _fclose(lf.f);
        lf.f = FUN_003465b3(filename, "rb");
        if (lf.f == 0) {
            status = FUN_003397c0(L, fnameindex);
            return status;
        }
        while ((c = _getc(lf.f)) != -1 && c != 0x1b) {
        }
        lf.extraline = 0;
    }
    _ungetc(c, lf.f);
    status = FUN_00213b20(L, FUN_00339770, &lf, FUN_00213190(L, -1));
    readstatus = (unsigned int)lf.f->flag & 0x20;
    if (lf.f != &DAT_004d99f0) {
        _fclose(lf.f);
    }
    if (readstatus) {
        FUN_00212d80(L, fnameindex);
        const char *fname = FUN_00213190(L, fnameindex) + 1;
        const char *serr = FUN_00347b53(*FUN_00347ba4());
        FUN_00213470(L, "cannot read %s: %s", fname, serr);
        FUN_00212de0(L, fnameindex);
        return 2;
    }
    FUN_00212de0(L, fnameindex);
    return status;
}


// 0x00339c30 FUN_00339c30 (181 B): equivalent/0x00339c30.cpp
// sym: _FUN_00339c30
// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 6/6)
// FUN_00339c30 @ 0x00339c30
// luaL_argerror
extern "C" int __cdecl FUN_00339c30(LuaVMState* state, int argument, const char* message) {
    LuaVMDebug info;
    FUN_00213fc0(state, 0, &info);
    FUN_00214bd0(state, "n", &info);
    const char* kind = info.namewhat;
    const char* method = "method";
    int i;
    for (i = 0; i < 7; ++i) {
        if (kind[i] != method[i]) break;
    }
    int result;
    if (i == 7 && --argument == 0) {
        result = FUN_00338e20(state, "calling `%s' on bad self (%s)", info.name, message);
    } else {
        if (!info.name) info.name = "?";
        result = FUN_00338e20(state, "bad argument #%d to `%s' (%s)", argument, info.name, message);
    }
    return result;
}

} // namespace fn_fe093b2d
