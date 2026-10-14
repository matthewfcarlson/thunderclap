class Base {
  public:
    Base();
    virtual void V0();
};

class Track : public Base {
  public:
    Track();
    virtual void V1();
    char pad[4];
    int mBase8;
    int mC;
    int m10;
};

Track::Track() : Base() {
    mC = 0;
    m10 = 0;
    *(int*)this = 0x417c28;
    mBase8 = 1;
}
