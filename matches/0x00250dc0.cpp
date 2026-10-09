class Name {
  public:
    void Init(const char*, int);
    int a;
    int b;
    int c;
};
class Base {
  public:
    Base();
    virtual void Foo();
    char pad[4];
};
class SeqEventStopTrack : public Base {
  public:
    SeqEventStopTrack();
    virtual void Foo();
    int b;
    int c;
    Name name;
    char flag;
};
SeqEventStopTrack::SeqEventStopTrack() : Base() {
    b = 0;
    c = 0;
    name.Init("MySeqTrack", 2);
    flag = 0;
}
