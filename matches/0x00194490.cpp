extern void* g_vftable_194490[];
void operator delete(void*);
void operator delete[](void*);
struct T1 {
    void Fini();
};
struct T2 {
    void Fini();
};
class Track_194490 {
  public:
    void* vptr;
    void Fin();
};
class FireMissileTrack_194490 : public Track_194490 {
  public:
    char pad10[0xc];
    T1 m10;
    char pad18[0x7];
    T1 m18;
    char pad20[0x7];
    T1 m20;
    char pad38[0x17];
    T1 m38;
    char padbc[0x83];
    T2 mbc;
    char padc8[0xb];
    T2 mc8;
    char paddc[0x13];
    void* mdc;
    char pade8[0x8];
    T1 me8;
    char pad100[0x17];
    T2 m100;
    char pad128[0x27];
    T1 m128;
    ~FireMissileTrack_194490() throw();
};
FireMissileTrack_194490::~FireMissileTrack_194490() throw() {
    vptr = g_vftable_194490;
    operator delete[](mdc);
    m128.Fini();
    m100.Fini();
    me8.Fini();
    mc8.Fini();
    mbc.Fini();
    m38.Fini();
    m20.Fini();
    m18.Fini();
    m10.Fini();
    Fin();
}
