class CTrack_5de00 {
  public:
    CTrack_5de00();
    virtual void f();
    char pad[8];
};
class Elem {
  public:
    Elem();
    char pad[8];
};
class CStunAnimationTrack : public CTrack_5de00 {
  public:
    CStunAnimationTrack();
    virtual void f();
    int z;
    Elem a;
    float x;
    int y, z2;
    float neg;
    int q;
    char pad2[4];
    Elem b;
    int i, j, k;
};
CStunAnimationTrack::CStunAnimationTrack()
    : CTrack_5de00(), z(0), a(), x(1.0f), y(0), z2(0), neg(-1.0f), q(0), b(), i(0), j(0), k(0) {}