extern void* vA[];
struct SubA {
    char pad[0x88];
    void Init() throw();
};
struct SubB {
    char pad[0x1c];
    void Init() throw();
};
struct Cfg {
    char pad[0x28];
    int a;
    int pad2;
    int b;
};
extern Cfg* g_cfg;
struct Obj0 {
    char pad[0x60];
    Obj0* Ctor() throw();
};
struct Obj1 {
    char pad[8];
    char tail[0x80];
    Obj1* Ctor(Obj0*) throw();
};
struct Ref {
    virtual void a() throw();
};
struct Name {
    void SetName(const char*) throw();
};
void* __cdecl FUN_0008d690(unsigned) throw();
void* __cdecl thunk_FUN_0008d690(unsigned) throw();
Ref* __cdecl FUN_002efa90(Obj1*, int, int) throw();
class O {
  public:
    void* vptr;
    int m4, m8;
    SubA sa;
    SubB s1, s2, s3;
    int me8, mec;
    int mf0;
    char cf4;
    int mf8;
    Ref* mfc;
    O() throw();
};
O::O() throw() {
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
    Obj1* r = (Obj1*)thunk_FUN_0008d690(0x80);
    Obj1* t = r ? r->Ctor(q) : 0;
    Ref* x = FUN_002efa90(t, 0, 0);
    mfc = x;
    x->a();
    ((Name*)((char*)t + 8))->SetName("ATGWorldCollision");
}
