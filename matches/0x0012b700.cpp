extern void* g_vftable_12b700[];
struct Sub_12b700 {
    char c;
};
void __fastcall Fin(Sub_12b700*) throw();
class Track_12b700 {
  public:
    void* vptr;
    void Fin();
};
class ThreatDodgeTrack_12b700 : public Track_12b700 {
  public:
    char pad[0x1c];
    Sub_12b700 sub;
    void F();
    ~ThreatDodgeTrack_12b700() throw();
};
extern void __fastcall SubFini(Sub_12b700*) throw();
ThreatDodgeTrack_12b700::~ThreatDodgeTrack_12b700() throw() {
    vptr = g_vftable_12b700;
    SubFini(&sub);
    Fin();
}
