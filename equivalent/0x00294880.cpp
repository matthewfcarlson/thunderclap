// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00294880 @ 0x00294880
struct Mat { char data[0x40]; void FUN_0022b980(); };
namespace pure3d {
class View {
  public:
    View();
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    int refCount;
    int f08, f0c;
    float f10, f14;
    int f18;
    unsigned int ambient;
    unsigned int clearColor;
    float f24;
    int f28, f2c, f30, f34, f38;
    int zeros[32];
    unsigned char flag;
    char pad_bd[3];
    Mat m0;
    Mat m1;
};
}
pure3d::View::View() {
    refCount = 0;
    f08 = 0;
    f0c = 0;
    f18 = 0;
    clearColor = 0xff000000;
    f28 = 0;
    ambient = 0xff101010;
    f14 = 1.0f;
    f10 = 1.0f;
    f24 = 1.0f;
    for (int i = 0; i < 32; i++) zeros[i] = 0;
    f2c = 3;
    flag = 0;
    f30 = -1;
    f38 = 0;
    f34 = 0;
    m0.FUN_0022b980();
    m1.FUN_0022b980();
}
