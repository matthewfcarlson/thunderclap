extern "C" char DAT_004272f0[];
class JointDriver {
  public:
    char pad[0x18];
    void Init();
    JointDriver(int arg);
};
extern void BaseInit();
extern int gCount;
extern int gMax;
JointDriver::JointDriver(int arg) {
    BaseInit();
    *(int*)this = ((int)DAT_004272f0);
    *(int*)((char*)this + 0x10) = arg;
    *(int*)((char*)this + 0x14) = 3;
    ((JointDriver*)((char*)this + 0x18))->Init();
    int a = gCount;
    int b = gMax;
    a++;
    gCount = a;
    if (a > b)
        gMax = a;
}
