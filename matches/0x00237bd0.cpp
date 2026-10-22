class Track_237bd0 {
  public:
    Track_237bd0();
    virtual void f();
    char pad[4];
};
class PartA {
  public:
    PartA();
    char pad[12];
};
class PartB {
  public:
    PartB();
};
class SequenceTrack : public Track_237bd0 {
  public:
    SequenceTrack();
    virtual void f();
    int flag;
    PartA a;
    int other;
    PartB b;
};
SequenceTrack::SequenceTrack() : Track_237bd0(), a(), other(1), b() {
    flag = 1;
}