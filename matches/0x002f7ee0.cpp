extern void* vA[];
struct SubA_2f7ee0 {
    char pad[0x88];
    void Init() throw();
};
struct SubB_2f7ee0 {
    char pad[0x1c];
    void Init() throw();
};
struct Cfg_2f7ee0 {
    char pad[0x28];
    int a;
    int pad2;
    int b;
};
extern Cfg_2f7ee0* g_cfg;
struct Obj0 {
    char pad[0x60];
    Obj0* Ctor() throw();
};
struct Obj1_2f7ee0 {
    char pad[8];
    char tail[0x80];
    Obj1_2f7ee0* Ctor(Obj0*) throw();
};
struct Ref_2f7ee0 {
    virtual void a() throw();
};
struct Name_2f7ee0 {
    void SetName(const char*) throw();
};
void* __cdecl FUN_0008d690(unsigned) throw();
void* __cdecl thunk_FUN_0008d690(unsigned) throw();
Ref_2f7ee0* __cdecl FUN_002efa90(Obj1_2f7ee0*, int, int) throw();
class O_2f7ee0 {
  public:
    void* vptr;
    int m4, m8;
    SubA_2f7ee0 sa;
    SubB_2f7ee0 s1, s2, s3;
    int me8, mec;
    int mf0;
    char cf4;
    int mf8;
    Ref_2f7ee0* mfc;
    O_2f7ee0() throw();
};
O_2f7ee0::O_2f7ee0() throw() {
    vptr = vA;
    m4 = 0;
    m8 = 0;
    sa.Init();
    s1.Init();
    s2.Init();
    s3.Init();
    cf4 = 0;
    mf8 = 3;
    me8 = g_cfg->b;
    mec = g_cfg->a;
    Obj0* p = (Obj0*)FUN_0008d690(0x60);
    Obj0* q = p ? p->Ctor() : 0;
    Obj1_2f7ee0* r = (Obj1_2f7ee0*)thunk_FUN_0008d690(0x80);
    Obj1_2f7ee0* t = r ? r->Ctor(q) : 0;
    Ref_2f7ee0* x = FUN_002efa90(t, 0, 0);
    mfc = x;
    x->a();
    ((Name_2f7ee0*)((char*)t + 8))->SetName("ATGWorldCollision");
}
