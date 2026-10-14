extern "C" char DAT_004272f0[];
extern int gCount_2248a0;
extern int gMax_2248a0;
class Base_2248a0 {
  public:
    void Init();
};
class Part_2248a0 {
  public:
    void Init();
};
class JointDriver {
  public:
    int* vptr;
    char pad[12];
    int mValue;
    int mState;
    char pad2[4];
    JointDriver* Init();
};
JointDriver* JointDriver::Init() {
    ((Base_2248a0*)this)->Init();
    this->vptr = (int*)((int)DAT_004272f0);
    mValue = 0;
    mState = 3;
    ((Part_2248a0*)((char*)this + 0x18))->Init();
    ++gCount_2248a0;
    if (gCount_2248a0 <= gMax_2248a0) {
    } else
        gMax_2248a0 = gCount_2248a0;
    return this;
}