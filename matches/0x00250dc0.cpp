class Name_250dc0 {
  public:
    void Init(const char*, int);
    int a;
    int b;
    int c;
};
class Base_250dc0 {
  public:
    Base_250dc0();
    virtual void Foo();
    char pad[4];
};
class SeqEventStopTrack : public Base_250dc0 {
  public:
    SeqEventStopTrack();
    virtual void Foo();
    int b;
    int c;
    Name_250dc0 name;
    char flag;
};
SeqEventStopTrack::SeqEventStopTrack() : Base_250dc0() {
    b = 0;
    c = 0;
    name.Init("MySeqTrack", 2);
    flag = 0;
}
