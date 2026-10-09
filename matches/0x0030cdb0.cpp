class PhysicsJointBase {
  public:
    void Init(int, int, int);
};
class PhysicsJoint1D : public PhysicsJointBase {
  public:
    char pad0[0xf8];
    volatile unsigned char mFlag;
    char pad1[3];
    volatile int mFC, m100, m104, m108, m10c, m110, m114, m118, m11c;
    PhysicsJoint1D* Init1(int, int, int);
};
PhysicsJoint1D* PhysicsJoint1D::Init1(int a, int b, int c) {
    PhysicsJointBase::Init(a, b, c);
    mFlag = 0;
    m108 = 0;
    m11c = 0;
    m118 = 0;
    m114 = 0;
    m110 = 0;
    m10c = 0;
    *(volatile int*)((char*)this) = 0x431ed4;
    *(volatile unsigned short*)((char*)this + 6) = 1;
    m104 = 0;
    m100 = 0;
    mFC = 0;
    return this;
}