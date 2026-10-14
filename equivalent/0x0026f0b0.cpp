// STATUS: equivalent (tools/equiv.py level 3: 67 inputs, branch coverage 3/4, incomplete)
// FUN_0026f0b0 @ 0x0026f0b0
namespace core {
struct A_26f0b0 { virtual void a(); };
struct B_26f0b0 { virtual void b(); char pad[4]; };
struct C_26f0b0 { virtual void c(); };
struct Device_26f0b0 { virtual void f0(); virtual void f1(); char pad[12]; int status; };
class XboxDrive : public A_26f0b0, public B_26f0b0, public C_26f0b0 {
public:
 char padding[0xa8];
 Device_26f0b0 *device;
 char middle[8];
 char path[0x11c];
 void *handle;
 virtual void driveMethod();
 void FUN_00272840();
 ~XboxDrive();
};
}
extern int DAT_00528408;
extern int DAT_0052840c;
void __cdecl FUN_0026d830(void *);
core::XboxDrive::~XboxDrive() {
 if (device->status == 1) {
  device->f1();
  FUN_0026d830(handle);
  if (path[0]=='D' && path[1]==':' && path[2]==0) DAT_00528408=0;
  else DAT_0052840c=0;
 }
 FUN_00272840();
}
