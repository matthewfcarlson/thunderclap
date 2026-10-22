extern "C" void _ReadWriteBarrier();
extern void* g_vftable_11ff60[];
class Ref_11ff60 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_11ff60 {
  public:
    void* vptr;
    void Fin();
};
void Free(void*) throw();
struct Sub_11ff60 {
    char c;
};
void __fastcall SubFini(Sub_11ff60*) throw();
void __fastcall SubFini2(Sub_11ff60*) throw();
void __fastcall SubFini3(Sub_11ff60*) throw();
class RoutAction_11ff60 : public Action_11ff60 {
  public:
    char p34[48];
    void* m34;
    Ref_11ff60* m38;
    Ref_11ff60* m3c;
    char p60[32];
    Sub_11ff60 s60;
    ~RoutAction_11ff60() throw();
};
RoutAction_11ff60::~RoutAction_11ff60() throw() {
    vptr = g_vftable_11ff60;
    _ReadWriteBarrier();
    if (m3c) {
        m3c->Release();
        m3c = 0;
    }
    if (m38) {
        m38->Release();
        m38 = 0;
    }
    if (m34)
        m34 = 0;
    SubFini(&s60);
    Fin();
}
