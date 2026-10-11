extern "C" char DAT_004272f0[];
extern int gCount;
extern int gMax;
class Base {
  public:
    void Init();
};
class Part {
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
    ((Base*)this)->Init();
    this->vptr = (int*)((int)DAT_004272f0);
    mValue = 0;
    mState = 3;
    ((Part*)((char*)this + 0x18))->Init();
    ++gCount;
    if (gCount <= gMax) {
    } else
        gMax = gCount;
    return this;
}