class Base {
  public:
    Base();
    virtual void fn();
};
class Part {
  public:
    Part();
};
class StopTrack : public Base {
  public:
    StopTrack();
    virtual void fn();
    char pad[8];
    int value;
    float speed;
    Part part;
};
StopTrack::StopTrack() : Base(), value(0), speed(-1.0f), part() {
    *(int*)((char*)this + 8) = 1;
}