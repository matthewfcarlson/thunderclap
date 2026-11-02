// STATUS: equivalent (tools/equiv.py level 3: 3027 inputs, branch coverage 11/12, incomplete)
// FUN_00217cf0 @ 0x00217cf0
struct TString;
struct TObject_217cf0 {
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

extern "C" int FUN_00217cf0(void *L, const void *l, const void *r)
{
    if (((const TObject_217cf0 *)l)->tt != ((const TObject_217cf0 *)r)->tt)
        return FUN_00214d80((LState *)((LState *)L), (int *)(const TObject_217cf0 *)((const TObject_217cf0 *)l), (int *)(const TObject_217cf0 *)((const TObject_217cf0 *)r));
    if (((const TObject_217cf0 *)l)->tt == 3)
        return ((const TObject_217cf0 *)l)->n < ((const TObject_217cf0 *)r)->n;
    if (((const TObject_217cf0 *)l)->tt == 4)
        return FUN_00217c80((const TString *)(((const TObject_217cf0 *)l)->s), (const TString *)(((const TObject_217cf0 *)r)->s)) < 0;
    int res = FUN_00217be0((LState *)((LState *)L), (const TObject_217cf0 *)((const TObject_217cf0 *)l), 0xb, (const TObject_217cf0 *)((const TObject_217cf0 *)r));
    if (res == -1)
        return FUN_00214d80((LState *)((LState *)L), (int *)(const TObject_217cf0 *)((const TObject_217cf0 *)l), (int *)(const TObject_217cf0 *)((const TObject_217cf0 *)r));
    return res;
}
