extern void* DAT_004316e8[];
struct SubA_2f7ee0 {
    char pad[0x88];
    void Init() throw();
};
struct SymMatrix_2f7ee0 {
    char pad[0x1c];
    void Init() throw();
};
struct Cfg_2f7ee0 {
    char pad[0x28];
    int a;
    int pad2;
    int b;
};
extern Cfg_2f7ee0* DAT_00554c10;
struct CollisionWall_2f7ee0 {
    char pad[0x60];
    CollisionWall_2f7ee0* Ctor() throw();
};
struct CollisionObject_2f7ee0 {
    char pad[8];
    char tail[0x80];
    CollisionObject_2f7ee0* Ctor(CollisionWall_2f7ee0*) throw();
};
struct Ref_2f7ee0 {
    virtual void a() throw();
};
struct Name_2f7ee0 {
    void SetName(const char*) throw();
};
void* __cdecl FUN_0008d690(unsigned) throw();
void* __cdecl thunk_FUN_0008d690(unsigned) throw();
Ref_2f7ee0* __cdecl FUN_002efa90(CollisionObject_2f7ee0*, int, int) throw();
class ImpulseBasedCollisionSolver_2f7ee0 {
  public:
    void* vptr;
    int m4, m8;
    SubA_2f7ee0 sa;
    SymMatrix_2f7ee0 s1, s2, s3;
    int me8, mec;
    int mf0;
    char cf4;
    int mf8;
    Ref_2f7ee0* mfc;
    ImpulseBasedCollisionSolver_2f7ee0() throw();
};
ImpulseBasedCollisionSolver_2f7ee0::ImpulseBasedCollisionSolver_2f7ee0() throw() {
    vptr = DAT_004316e8;
    m4 = 0;
    m8 = 0;
    sa.Init();
    s1.Init();
    s2.Init();
    s3.Init();
    cf4 = 0;
    mf8 = 3;
    me8 = DAT_00554c10->b;
    mec = DAT_00554c10->a;
    CollisionWall_2f7ee0* p = (CollisionWall_2f7ee0*)FUN_0008d690(0x60);
    CollisionWall_2f7ee0* q = p ? p->Ctor() : 0;
    CollisionObject_2f7ee0* r = (CollisionObject_2f7ee0*)thunk_FUN_0008d690(0x80);
    CollisionObject_2f7ee0* t = r ? r->Ctor(q) : 0;
    Ref_2f7ee0* x = FUN_002efa90(t, 0, 0);
    mfc = x;
    x->a();
    ((Name_2f7ee0*)((char*)t + 8))->SetName("ATGWorldCollision");
}
