class Base {
  public:
    virtual void f();
    Base();
    char pad[8];
};
struct Pair {
    int a, b;
    Pair() : a(0), b(0) {}
};
class Track_170d70 : public Base {
  public:
    Pair pair;
    Track_170d70() : pair() {}
};
struct Tail {
    int a, b;
    float t;
    Tail() : a(0), b(0), t(-1.0f) {}
};
class TeleportToLocatorTrack_170d70 : public Track_170d70 {
  public:
    virtual void f();
    TeleportToLocatorTrack_170d70();
    Tail tail;
};
TeleportToLocatorTrack_170d70::TeleportToLocatorTrack_170d70() {
    *(int*)((char*)this + 8) = 1;
}