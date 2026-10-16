class Base {
  public:
    Base();
    virtual void v0();
    char pad[8];
};
struct Pair {
    int b, c;
    void reset() {
        b = 0;
        c = 0;
    }
};
class TeleportTrack : public Base {
  public:
    TeleportTrack();
    virtual void v0();
    int a;
    Pair pair;
    float d;
};
TeleportTrack::TeleportTrack() : Base(), a(0) {
    pair.reset();
    d = -1.0f;
    *(int*)((char*)this + 8) = 1;
}