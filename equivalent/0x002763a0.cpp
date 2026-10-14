// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_002763a0 @ 0x002763a0
// equiv-map: ??_7File@core@@6BIFileBase@1@@ = 0x0042bd3c
// equiv-map: ??_7File@core@@6BIMutable@1@@ = 0x0042bd30
namespace core {
class IFileBase {
  public:
    virtual void f0();
    virtual void f1();
};
class IMutable {
  public:
    virtual void m0();
    virtual void m1();
    int refCount;
};
class IDevice_2763a0 {
  public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
};
struct Counters {
    int w[11];
    void FUN_00277c00();
};
class SaveGameOpenRequest {
  public:
    SaveGameOpenRequest* FUN_00275060(void* file, int a, int b, int c, int d);
};
class File : public IFileBase, public IMutable {
  public:
    File(IDevice_2763a0* device, const char* name, int flag, int a4, int a5, int a6, void* userData);
    virtual void f0();
    virtual void f1();
    virtual void m0();
    virtual void m1();
    IDevice_2763a0* device;
    void* userData;
    int field_14;
    int field_18;
    char field_1c;
    char flag;
    char name[0x100];
    char nameEnd;
    char pad_11f;
    int field_120;
    int field_124;
    int field_128;
    Counters counters;
    char pad_158[8];
    char field_160;
    char pad_161[3];
    int field_164;
};
}
class DeviceHelper {
  public:
    void FUN_00272b60(core::SaveGameOpenRequest* req, void* userData, int zero);
};
const char* FUN_002705f0();
void* FUN_00273560(unsigned size);
int thunk_FUN_00271cf0(char* dst, const char* src, unsigned n);
char* strncpy(char* dst, const char* src, unsigned n);

core::File::File(IDevice_2763a0* dev, const char* nm, int fl, int a4, int a5, int a6, void* ud) {
    refCount = 1;
    device = dev;
    userData = ud;
    field_14 = 0;
    field_18 = 0;
    field_1c = 0;
    flag = (char)fl;
    field_120 = 0;
    field_124 = 0;
    field_128 = 0;
    counters.FUN_00277c00();
    field_160 = 1;
    field_164 = 0x800;
    FUN_002705f0();
    device->d0();
    if (thunk_FUN_00271cf0(name, nm, 0x100) < 0) {
        strncpy(name, nm, 0x100);
        nameEnd = 0;
    }
    device->d6();
    SaveGameOpenRequest* req = (SaveGameOpenRequest*)FUN_00273560(0x1c);
    if (req != 0) {
        req = req->FUN_00275060(this, a4, fl, a5, a6);
    }
    ((DeviceHelper*)device)->FUN_00272b60(req, userData, 0);
}
