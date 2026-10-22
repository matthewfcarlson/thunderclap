extern void* g_vftable_23f170[];
struct Sub_23f170 {
    void Fin();
};
class Track_23f170 {
  public:
    void* vptr;
    void Fin();
};
class BreakPointTrack_23f170 : public Track_23f170 {
  public:
    char pad[0xc];
    Sub_23f170 sub;
    void f();
};
void BreakPointTrack_23f170::f() {
    vptr = g_vftable_23f170;
    sub.Fin();
    Fin();
}
