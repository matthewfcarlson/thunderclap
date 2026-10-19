extern "C" char hulk_at_00417c24[];
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
    *(int*)this = ((int)(hulk_at_00417c24 + 0x4));
    mBase8 = 1;
}
