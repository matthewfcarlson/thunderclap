class Track_23e530 {
  public:
    Track_23e530();
    virtual void fn();
};
class Part {
  public:
    Part();
};
class StopTrack : public Track_23e530 {
  public:
    StopTrack();
    virtual void fn();
    char pad[8];
    int value;
    float speed;
    Part part;
};
StopTrack::StopTrack() : Track_23e530(), value(0), speed(-1.0f), part() {
    *(int*)((char*)this + 8) = 1;
}