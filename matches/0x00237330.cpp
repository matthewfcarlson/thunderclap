extern void* g_vA[];
struct SubA_237330 {
    void* v;
    void Fin() throw();
};
struct SubB_237330 {
    void* v;
    void Fin() throw();
};
class Track_237330 {
  public:
    void* vptr;
    void Fin();
};
class OpportunityTrack_237330 : public Track_237330 {
  public:
    char pad[0x18 - 4];
    SubB_237330 b;
    char pad2[0x28 - 0x1c];
    SubA_237330 a;
    ~OpportunityTrack_237330() throw();
};
OpportunityTrack_237330::~OpportunityTrack_237330() throw() {
    vptr = g_vA;
    a.Fin();
    b.Fin();
    Fin();
}
