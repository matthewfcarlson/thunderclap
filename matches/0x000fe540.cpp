extern "C" void _ReadWriteBarrier();
extern void* g_vftable_fe540[];
extern void* g_vftable2[];
class Ref_fe540 {
  public:
    virtual void F0();
    virtual void Release();
};
struct Vec_fe540 {
    int a;
    void Destroy();
};
class CActorGolem_fe540 {
  public:
    void* vptr;
    char padb[0xf8 - 4];
    int mf8;
    ~CActorGolem_fe540() throw();
};
class CCharacterGolem_fe540 : public CActorGolem_fe540 {
  public:
    char padc[4];
    Ref_fe540* m100;
    Ref_fe540* m104;
    Ref_fe540* m108;
    Ref_fe540* m10c;
    Ref_fe540* m110;
    Ref_fe540* m114;
    Vec_fe540 m118;
    ~CCharacterGolem_fe540() throw();
};
CCharacterGolem_fe540::~CCharacterGolem_fe540() throw() {
    vptr = g_vftable_fe540;
    _ReadWriteBarrier();
    if (m100) {
        m100->Release();
        m100 = 0;
    }
    if (m104) {
        m104->Release();
        m104 = 0;
    }
    if (m108) {
        m108->Release();
        m108 = 0;
    }
    if (m10c) {
        m10c->Release();
        m10c = 0;
    }
    if (m110) {
        m110->Release();
        m110 = 0;
    }
    if (m114) {
        m114->Release();
        m114 = 0;
    }
    m118.Destroy();
    mf8 = 0;
    vptr = g_vftable2;
}
