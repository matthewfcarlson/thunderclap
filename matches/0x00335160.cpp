typedef unsigned char u8_335160;
extern char refvt_335160, basevt;
extern int g_335160;
void __cdecl cleanup(int, void*);
namespace movie { class BinkCallback {
  public:
    void* vptr;
    int m;
    void* refptr;
    BinkCallback* vfunc_0(u8_335160 flag);
}; }
movie::BinkCallback* movie::BinkCallback::vfunc_0(u8_335160 flag) {
    movie::BinkCallback* p = this;
    if (p)
        p = (movie::BinkCallback*)((char*)p + 8);
    else
        p = (movie::BinkCallback*)0;
    p->vptr = &refvt_335160;
    g_335160 = m;
    vptr = &basevt;
    if (flag & 1)
        cleanup(g_335160, this);
    return this;
}