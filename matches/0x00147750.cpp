extern void* g_vt_147750[];
struct Sub_147750 {
    void Fin() throw();
};
class Track_147750 {
  public:
    void* vptr;
    ~Track_147750() throw();
};
class GrappleHitReactionTrack_147750 : public Track_147750 {
  public:
    char pad[0x20 - 4];
    Sub_147750 sub;
    ~GrappleHitReactionTrack_147750() throw();
};
GrappleHitReactionTrack_147750::~GrappleHitReactionTrack_147750() throw() {
    vptr = g_vt_147750;
    sub.Fin();
}
