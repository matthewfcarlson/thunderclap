class Base_13a130 {
  public:
    virtual void f();
    char pad[8];
    Base_13a130();
};
class Part_13a130 {
  public:
    Part_13a130();
    char pad[8];
};
class AnimationTrack : public Base_13a130 {
  public:
    virtual void f();
    int zero;
    float negative;
    char pad0[4];
    Part_13a130 part1;
    float one;
    int z24, z28;
    float neg2;
    int z30;
    char yes;
    char pad1[3];
    Part_13a130 part2;
    int z40;
    float a, b;
    AnimationTrack();
};
AnimationTrack::AnimationTrack()
    : zero(0), negative(-1.0f), one(1.0f), z24(0), z28(0), neg2(-1.0f), z30(0), yes(1), z40(0), a(0.1f),
      b(0.1f) {}