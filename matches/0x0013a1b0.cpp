extern void* g_vftable_13a1b0[];
class Str_13a1b0 {
  public:
    void Init();
};
class Track_13a1b0 {
  public:
    void* vptr;
    void Fin();
};
class AnimationTrack_13a1b0 : public Track_13a1b0 {
  public:
    char pad[0x14];
    Str_13a1b0 s18;
    char pad2[0x1f];
    Str_13a1b0 s38;
    ~AnimationTrack_13a1b0();
};
AnimationTrack_13a1b0::~AnimationTrack_13a1b0() {
    vptr = g_vftable_13a1b0;
    s38.Init();
    s18.Init();
    Fin();
}
