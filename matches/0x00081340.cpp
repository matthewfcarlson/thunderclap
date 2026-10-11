extern "C" void _ReadWriteBarrier();
extern void* gV[];
class Ref {
  public:
    virtual void F0();
    virtual void Release();
};
class Base {
  public:
    void* vptr;
    void Fin();
};
class Civ;
class Plr {
  public:
    char pad[0x328];
    Ref* m328;
    Civ* F36020();
    Civ* F36030();
    void F3b160(int);
    void F3b190(int);
    void F3ffa0(int, int);
};
class Mgr {
  public:
    char pad[0x10];
    struct Sub* m10;
    char pad2[0x20 - 0x14];
    struct Pl* m20;
};
struct Pl {
    char pad[0x124];
    Plr* m124;
};
struct Sub {
    void F1b43f0(Civ*);
};
struct Tmp {
    void F1c3b80();
};
Tmp* __stdcall F1c3d90(void*);
extern Mgr* g_mgr;
class Civ : public Base {
  public:
    char pad[0xb8 - 4];
    Ref* mb8;
    char pad2[0xe8 - 0xbc];
    Ref* me8;
    char pad3[4];
    Ref* mf0;
    char pad4[0x100 - 0xf4];
    Ref* m100;
    ~Civ();
};
Civ::~Civ() {
    vptr = gV;
    _ReadWriteBarrier();
    Pl* pl = g_mgr->m20;
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
    g_mgr->m10->F1b43f0(this);
    F1c3d90(&pad[4])->F1c3b80();
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
