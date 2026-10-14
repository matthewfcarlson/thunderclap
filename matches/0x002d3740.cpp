extern "C" void _ReadWriteBarrier();
class Base_2d3740 {
  public:
    Base_2d3740() throw();
    virtual void a();
    char pad[0xc];
};
struct Init1_2d3740 {
    Init1_2d3740() throw() {
        m10 = 0;
        m14 = 0;
        m18 = 0;
        m1c = 0;
        m20 = 0;
        m28 = 0;
    }
    char m10;
    int m14, m18, m1c, m20, m24, m28;
};
class PPG : public Base_2d3740, public Init1_2d3740 {
  public:
    PPG() throw();
    virtual void a();
    int m2c, m30, m34, m38, m3c, m40;
    float m44, m48, m4c;
};
PPG::PPG() throw() {
    _ReadWriteBarrier();
    m2c = 0;
    m30 = 0;
    m38 = 0;
    m3c = 0;
    m40 = 0;
    m44 = 1.0f;
    m48 = 1.0f;
    m4c = 1.0f;
}
