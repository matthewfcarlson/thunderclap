extern "C" void _ReadWriteBarrier();
extern void* g_vftable_252680[];
extern void* g_vftable2[];
void operator delete(void*);
class Ref_252680 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_252680 {
  public:
    void* vptr;
    void Fin();
};

extern char g_pool_252680;
void Free(void*, void*);
class Obj_252680 : public Base_252680 {
  public:
    Obj_252680* f2(unsigned char flags);
};
Obj_252680* Obj_252680::f2(unsigned char flags) {
    vptr = g_vftable_252680;
    if (flags & 1)
        Free(&g_pool_252680, this);
    return this;
}
