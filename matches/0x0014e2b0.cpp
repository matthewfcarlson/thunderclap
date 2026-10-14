extern void* g_vftable[];
class Base {
  public:
    Base();
    void* vptr;
};
class HitDamageTrack : public Base {
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
