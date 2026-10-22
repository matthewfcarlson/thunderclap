extern void* gA_5dbb0[];
struct S_5dbb0 {
    int a;
    void Fini();
};
struct T_5dbb0 {
    int a;
    void Fini();
};
class CTrack_5dbb0 {
  public:
    void* vptr;
    void Fin();
};
class COpportunityBallTrack_5dbb0 : public CTrack_5dbb0 {
  public:
    char pad[0x18 - 4];
    S_5dbb0 s18;
    char pad2[0x34 - 0x1c];
    T_5dbb0 t34;
    char pad3[0x40 - 0x38];
    T_5dbb0 t40;
    ~COpportunityBallTrack_5dbb0();
};
COpportunityBallTrack_5dbb0::~COpportunityBallTrack_5dbb0() {
    vptr = gA_5dbb0;
    t40.Fini();
    t34.Fini();
    s18.Fini();
    Fin();
}
