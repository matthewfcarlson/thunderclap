class Track_143720 {
  public:
    Track_143720();
    virtual void f();
    char pad[8];
};
class Vec {
  public:
    Vec();
    char pad[8];
};
class HitEffectTrack : public Track_143720 {
  public:
    HitEffectTrack();
    virtual void f();
    int mC;
    float m10;
    char pad14[4];
    Vec v18;
    float m20;
    char pad24[4];
    Vec v28;
    float m30;
    int m34;
};
HitEffectTrack::HitEffectTrack() : Track_143720(), mC(0), m10(-1.0f), v18(), m20(1.0f), v28(), m30(1.0f), m34(0) {
    *(int*)((char*)this + 8) = 1;
}