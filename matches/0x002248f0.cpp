extern "C" char DAT_004272f0[];
class JointDriver {
  public:
    char pad[0x18];
    void Init();
    JointDriver(int arg);
};
extern void __fastcall BaseInit(void*);
extern int gCount_2248f0;
extern int gMax_2248f0;
JointDriver::JointDriver(int arg) {
    BaseInit((void*)(this));
    *(int*)this = ((int)DAT_004272f0);
    *(int*)((char*)this + 0x10) = arg;
    *(int*)((char*)this + 0x14) = 3;
    ((JointDriver*)((char*)this + 0x18))->Init();
    int a = gCount_2248f0;
    int b = gMax_2248f0;
    a++;
    gCount_2248f0 = a;
    if (a > b)
        gMax_2248f0 = a;
}
