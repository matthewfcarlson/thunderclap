class Base_629a0 {
  public:
    Base_629a0();
    virtual void baseMethod();
    char pad[4];
};

class ThrowingTrack : public Base_629a0 {
  public:
    virtual void method1();
    int m8;
    int mC;
    float m10;
    ThrowingTrack();
};

ThrowingTrack::ThrowingTrack() {
    mC = 0;
    m10 = -1.0f;
    m8 = 1;
}
