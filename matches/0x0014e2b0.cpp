extern void* g_vftable[];
class Track_14e2b0 {
  public:
    Track_14e2b0();
    void* vptr;
};
class HitDamageTrack : public Track_14e2b0 {
  public:
    HitDamageTrack();
    char pad[8];
    int mFieldC;
    float mField10;
};
HitDamageTrack::HitDamageTrack() {
    vptr = g_vftable;
    mFieldC = 0;
    mField10 = 1.0f;
}
