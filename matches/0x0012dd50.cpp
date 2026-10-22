extern "C" void _ReadWriteBarrier();
extern void* g_vt_12dd50[];
void operator delete(void*);
class Ref_12dd50 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_12dd50 {
  public:
    void* vptr;
    void Fin();
};
class PostEvent_StringAction_12dd50 : public Action_12dd50 {
  public:
    char pad[32 - 4];
    Ref_12dd50* m;
    PostEvent_StringAction_12dd50* f2(unsigned char flags);
};
PostEvent_StringAction_12dd50* PostEvent_StringAction_12dd50::f2(unsigned char flags) {
    vptr = g_vt_12dd50;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
    if (flags & 1)
        operator delete(this);
    return this;
}
