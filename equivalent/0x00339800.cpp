// STATUS: equivalent (tools/equiv.py level 3: 3033 inputs, branch coverage 24/24)
// FUN_00339800 @ 0x00339800
// cl-flags: /GS
// equiv-conv: FUN_003397c0 edi ebx
#include "decls/data/lua.h"

extern "C" LuaVMFile DAT_004d99f0;  // stdin (the CRT's _iob[0])

extern "C" int __cdecl FUN_00212d70(LuaVMState *L);
extern "C" void __cdecl FUN_00212d80(LuaVMState *L, int idx);
extern "C" void __cdecl FUN_00212de0(LuaVMState *L, int idx);
extern "C" const char *__cdecl FUN_00213190(LuaVMState *L, int idx);
extern "C" void __cdecl FUN_00213380(LuaVMState *L, const char *s, unsigned int len);
extern "C" const char *__cdecl FUN_00213470(LuaVMState *L, const char *fmt, ...);
extern "C" int __cdecl FUN_00213b20(LuaVMState *L, LuaVMReader reader, void *data, const char *chunkname);
extern "C" const char *__cdecl FUN_00339770(LuaVMState *L, void *ud, unsigned int *size);
extern "C" int __cdecl FUN_003397c0(LuaVMState *L, int fnameindex);
extern "C" LuaVMFile *__cdecl FUN_003465b3(const char *name, const char *mode);  // fopen
extern "C" int *__cdecl FUN_00347ba4();                                           // _errno
extern "C" const char *__cdecl FUN_00347b53(int err);                             // strerror
extern "C" int __cdecl _getc(LuaVMFile *f);
extern "C" int __cdecl _ungetc(int c, LuaVMFile *f);
extern "C" int __cdecl _fclose(LuaVMFile *f);

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
