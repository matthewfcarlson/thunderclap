class Base {
  public:
    virtual void V0();
    Base(int a);
};

class CJointTrack : public Base {
  public:
    virtual void V1();
    char pad[0x0c];
    int mValue;
    CJointTrack(int a, int b);
};

CJointTrack::CJointTrack(int a, int b) : Base(a) {
    mValue = b;
}
