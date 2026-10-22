extern void* g_vftable_18f1d0[];
class Str_18f1d0 {
  public:
    void Init();
};
class Track_18f1d0 {
  public:
    void* vptr;
    char pad[12];
    Str_18f1d0 s;
    void Fin();
};
class ImpulseVelocityTrack_18f1d0 : public Track_18f1d0 {
  public:
    ~ImpulseVelocityTrack_18f1d0();
};
ImpulseVelocityTrack_18f1d0::~ImpulseVelocityTrack_18f1d0() {
    vptr = g_vftable_18f1d0;
    s.Init();
    Fin();
}
