extern "C" void _ReadWriteBarrier();
extern int vt1_2a11b0;
extern void Free(void*);
class Ref_2a11b0 {
  public:
    virtual void f0();
    virtual void Release();
};
class Entity_2a11b0 {
  public:
    void* vptr;
    ~Entity_2a11b0() throw();
};
class LightGroup_2a11b0 : public Entity_2a11b0 {
  public:
    char p[0xc];
    int n;
    int cap;
    Ref_2a11b0** arr;
    ~LightGroup_2a11b0() throw();
};
LightGroup_2a11b0::~LightGroup_2a11b0() throw() {
    vptr = &vt1_2a11b0;
    for (int i = 0; i < n; i++) {
        Ref_2a11b0* r = arr[i];
        if (r)
            r->Release();
    }
    n = 0;
    cap = 0;
    _ReadWriteBarrier();
    if (arr)
        Free(arr);
}
