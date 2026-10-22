extern void* g_vt_18cf00[];
struct Sub_18cf00 {
    void Fin() throw();
};
class Track_18cf00 {
  public:
    void* vptr;
    ~Track_18cf00() throw();
};
class VarAssignTrack_18cf00 : public Track_18cf00 {
  public:
    char pad[0x10 - 4];
    Sub_18cf00 sub;
    ~VarAssignTrack_18cf00() throw();
};
VarAssignTrack_18cf00::~VarAssignTrack_18cf00() throw() {
    vptr = g_vt_18cf00;
    sub.Fin();
}
