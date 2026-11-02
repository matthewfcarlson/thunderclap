// STATUS: equivalent (tools/equiv.py level 3: 3027 inputs, branch coverage 15/16, incomplete)
// FUN_00217d80 @ 0x00217d80
// Lua 5.0 luaV_lessequal
struct TString;
struct TObject_217d80 {
    int tt;
    union {
        float n;
        TString *s;
    };
};

struct LState;

extern "C" int __cdecl FUN_00214d80(void *, int *, int *);
// equiv-conv: FUN_00217be0 eax stack stack ebx
extern "C" int __cdecl FUN_00217be0(void *, const void *, int, const void *);
// equiv-conv: FUN_00217c80 ecx eax
extern "C" int __cdecl FUN_00217c80(const void *, const void *);

// equiv-conv: FUN_00217d80 edi esi stack
extern "C" int FUN_00217d80(const void *l, const void *r, void *L)
{
    if (((const TObject_217d80 *)l)->tt != ((const TObject_217d80 *)r)->tt)
        return FUN_00214d80((LState *)((LState *)L), (int *)(const TObject_217d80 *)((const TObject_217d80 *)l), (int *)(const TObject_217d80 *)((const TObject_217d80 *)r));
    if (((const TObject_217d80 *)l)->tt == 3)
        return ((const TObject_217d80 *)l)->n <= ((const TObject_217d80 *)r)->n;
    if (((const TObject_217d80 *)l)->tt == 4)
        return FUN_00217c80((const TString *)(((const TObject_217d80 *)l)->s), (const TString *)(((const TObject_217d80 *)r)->s)) <= 0;
    int res = FUN_00217be0((LState *)((LState *)L), (const TObject_217d80 *)((const TObject_217d80 *)l), 0xc, (const TObject_217d80 *)((const TObject_217d80 *)r));
    if (res != -1)
        return res;
    res = FUN_00217be0((LState *)((LState *)L), (const TObject_217d80 *)((const TObject_217d80 *)r), 0xb, (const TObject_217d80 *)((const TObject_217d80 *)l));
    if (res != -1)
        return res == 0;
    return FUN_00214d80((LState *)((LState *)L), (int *)(const TObject_217d80 *)((const TObject_217d80 *)l), (int *)(const TObject_217d80 *)((const TObject_217d80 *)r));
}
