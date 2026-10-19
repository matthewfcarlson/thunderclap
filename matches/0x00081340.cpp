extern "C" void _ReadWriteBarrier();
extern void* gV[];
class Ref_81340 {
  public:
    virtual void F0();
    virtual void Release();
};
class Base_81340 {
  public:
    void* vptr;
    void Fin();
};
class Civ;
class Plr {
  public:
    char pad[0x328];
    Ref_81340* m328;
    Civ* F36020();
    Civ* F36030();
    void F3b160(int);
    void F3b190(int);
    void F3ffa0(int, int);
};
class Mgr_81340 {
  public:
    char pad[0x10];
    struct Sub_81340* m10;
    char pad2[0x20 - 0x14];
    struct Pl* m20;
};
struct Pl {
    char pad[0x124];
    Plr* m124;
};
struct Sub_81340 {
    void F1b43f0(Civ*);
};
struct Tmp_81340 {
    void F1c3b80(void*);
};
Tmp_81340* __stdcall F1c3d90();
extern Mgr_81340* g_mgr_81340;
class Civ : public Base_81340 {
  public:
    char pad[0xb8 - 4];
    Ref_81340* mb8;
    char pad2[0xe8 - 0xbc];
    Ref_81340* me8;
    char pad3[4];
    Ref_81340* mf0;
    char pad4[0x100 - 0xf4];
    Ref_81340* m100;
    ~Civ();
};
Civ::~Civ() {
    vptr = gV;
    _ReadWriteBarrier();
    Pl* pl = g_mgr_81340->m20;
    if (pl) {
        Plr* p = pl->m124;
        if (p) {
            if (p->F36020() == this)
                p->F3b160(0);
            if (p->F36030() == this)
                p->F3b190(0);
            if (p->m328 == m100)
                p->F3ffa0(0, 0);
        }
    }
    g_mgr_81340->m10->F1b43f0(this);
    F1c3d90()->F1c3b80(&pad[4]);
    if (mb8) {
        mb8->Release();
        mb8 = 0;
    }
    if (me8) {
        me8->Release();
        me8 = 0;
    }
    if (mf0) {
        mf0->Release();
        mf0 = 0;
    }
    if (m100) {
        m100->Release();
        m100 = 0;
    }
    Fin();
}
