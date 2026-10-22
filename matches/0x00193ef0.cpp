class Track_193ef0 {
  public:
    Track_193ef0();
    virtual void dummy();
    char pad[4];
};
class Part {
  public:
    Part();
};
class MissilePunchTrack : public Track_193ef0 {
  public:
    MissilePunchTrack();
    char pad2[4];
    int a;
    float b;
    float c;
    Part part;
};
MissilePunchTrack::MissilePunchTrack() : Track_193ef0(), a(0), b(-1.0f), c(6.2831855f), part() {
    *(int*)((char*)this + 8) = 1;
}