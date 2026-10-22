class Base {
  public:
    Base();
    virtual void f();
    char pad[8];
};
class Zero {
  public:
    int x;
    Zero() : x(0) {}
};
class Track_14df50 : public Base {
  public:
    Zero a;
    float val;
    Zero b;
    Track_14df50() : a(), b() {}
};
class InterruptPriorityTrack_14df50 : public Track_14df50 {
  public:
    InterruptPriorityTrack_14df50();
    virtual void f();
};
InterruptPriorityTrack_14df50::InterruptPriorityTrack_14df50() {
    val = -1.0f;
    *(int*)((char*)this + 8) = 1;
}