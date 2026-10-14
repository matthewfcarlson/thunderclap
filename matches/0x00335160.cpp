typedef unsigned char u8_335160;
extern char refvt_335160, basevt;
extern int g_335160;
void __cdecl cleanup(int, void*);
class BinkCallback {
  public:
    void* vptr;
    int m;
    void* refptr;
    BinkCallback* vfunc_0(u8_335160 flag);
};
BinkCallback* BinkCallback::vfunc_0(u8_335160 flag) {
    BinkCallback* p = this;
    if (p)
        p = (BinkCallback*)((char*)p + 8);
    else
        p = (BinkCallback*)0;
    p->vptr = &refvt_335160;
    g_335160 = m;
    vptr = &basevt;
    if (flag & 1)
        cleanup(g_335160, this);
    return this;
}