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
class Mid : public Base {
  public:
    Zero a;
    float val;
    Zero b;
    Mid() : a(), b() {}
};
class hulkfight_motion_InterruptPriorityTrack : public Mid {
  public:
    hulkfight_motion_InterruptPriorityTrack();
    virtual void f();
};
hulkfight_motion_InterruptPriorityTrack::hulkfight_motion_InterruptPriorityTrack() {
    val = -1.0f;
    *(int*)((char*)this + 8) = 1;
}