extern "C" void _ReadWriteBarrier();
extern void* g_vftable_176370[];
class Ref_176370 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_176370 {
  public:
    void* vptr;
    void Fin();
};
void Free(void*) throw();
struct Sub_176370 {
    char c;
};
void __fastcall SubFini(Sub_176370*) throw();
void __fastcall SubFini2(Sub_176370*) throw();
class MoveJointAction_176370 : public Action_176370 {
  public:
    char p1c[24];
    void* m1c;
    Ref_176370* m20;
    Ref_176370* m24;
    Ref_176370* m28;
    ~MoveJointAction_176370() throw();
};
MoveJointAction_176370::~MoveJointAction_176370() throw() {
    vptr = g_vftable_176370;
    _ReadWriteBarrier();
    if (m24) {
        m24->Release();
        m24 = 0;
    }
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    Fin();
}
