// cl-flags: /Oy- /O1
struct ThrowInfo {
    unsigned attr;
    void* a;
    void* fwd;
    void* c;
};
struct Exc {
    unsigned code;
    unsigned flags;
    void* nx;
    void* addr;
    unsigned pad;
    unsigned n;
    unsigned p1;
    ThrowInfo* ti;
};
struct FuncInfo {
    unsigned magic;
    int maxState;
    void* u;
    int nTry;
};
extern "C" void __cdecl _inconsistency();
extern "C" void __cdecl FrameUnwindToState(void* rn, void* dc, FuncInfo* fi, int s);
extern "C" int __cdecl FUN_0035b9c2(Exc*, void*, void*, void*, FuncInfo*, unsigned char, int, void*);
typedef int(__cdecl* Fwd)(Exc*, void*, void*, void*, FuncInfo*, int, void*, int);

int __cdecl InternalCxxFrameHandler(Exc* e, void* rn, void* ctx, void* dc, FuncInfo* fi, int depth,
                                    void* marker, unsigned char rec) {
    if ((fi->magic & 0x1fffffff) != 0x19930520)
        _inconsistency();
    if (e->flags & 0x66) {
        if (fi->maxState != 0 && depth == 0)
            FrameUnwindToState(rn, dc, fi, -1);
    } else if (fi->nTry != 0) {
        if (e->code == 0xe06d7363 && e->n > 0x19930520) {
            Fwd f = (Fwd)e->ti->fwd;
            if (f)
                return f(e, rn, ctx, dc, fi, depth, marker, (int)rec);
        }
        FUN_0035b9c2(e, rn, ctx, dc, fi, rec, depth, marker);
    }
    return 1;
}