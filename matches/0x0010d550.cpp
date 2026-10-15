class Base {
  public:
    Base();
    virtual void f();
};
class Part {
  public:
    Part();
    char pad[8];
};
class SemaphoreWaitTrack : public Base {
    char gap[8];
    int a;
    float b;
    char gap2[4];
    Part part;
    char x, y;
    char gap3[2];
    int z;

  public:
    SemaphoreWaitTrack();
    virtual void f();
};
SemaphoreWaitTrack::SemaphoreWaitTrack() : Base(), a(0), b(-1.0f), part(), x(1), y(1), z(0) {}