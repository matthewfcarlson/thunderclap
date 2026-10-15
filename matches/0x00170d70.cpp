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
class Mid : public Base {
  public:
    Pair pair;
    Mid() : pair() {}
};
struct Tail {
    int a, b;
    float t;
    Tail() : a(0), b(0), t(-1.0f) {}
};
class hulkfight_motion_TeleportToLocatorTrack : public Mid {
  public:
    virtual void f();
    hulkfight_motion_TeleportToLocatorTrack();
    Tail tail;
};
hulkfight_motion_TeleportToLocatorTrack::hulkfight_motion_TeleportToLocatorTrack() {
    *(int*)((char*)this + 8) = 1;
}