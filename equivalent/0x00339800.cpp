// STATUS: equivalent (tools/equiv.py level 3: 20037 inputs, branch coverage 24/24)
// FUN_00339800 @ 0x00339800
// cl-flags: /GS
// FUN_00339800 @ 0x00339800
// equiv-conv: FUN_003397c0 edi ebx
#include "compat/ptr.h"
struct lua_State;

struct File {
    char pad0[0x0c];
    unsigned int flag;
};

struct LoadF {
    int extraline;
    File *f;
    char buff[512];
};

extern File DAT_004d99f0;

int __cdecl FUN_00212d70(lua_State *L);
void __cdecl FUN_00212d80(lua_State *L, int idx);
void __cdecl FUN_00212de0(lua_State *L, int idx);
const char *__cdecl FUN_00213190(lua_State *L, int idx);
void __cdecl FUN_00213380(lua_State *L, const char *s, hulk_uintptr len);
const char *__cdecl FUN_00213470(lua_State *L, const char *fmt, ...);
int __cdecl FUN_00213b20(lua_State *L, const char *(__cdecl *reader)(lua_State *, void *, unsigned int *),
                         void *data, const char *chunkname);
const char *__cdecl FUN_00339770(lua_State *L, void *ud, unsigned int *size);
int __cdecl FUN_003397c0(lua_State *L, int fnameindex);
File *__cdecl FUN_003465b3(const char *name, const char *mode);
int *__cdecl FUN_00347ba4();
const char *__cdecl FUN_00347b53(int err);
extern int __cdecl _getc(File *f);
extern int __cdecl _ungetc(int c, File *f);
extern int __cdecl _fclose(File *f);

// Lua 5.0 luaL_loadfile
int luaL_loadfile(lua_State *L, const char *filename)
{
    LoadF lf;
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
    readstatus = lf.f->flag & 0x20;
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
