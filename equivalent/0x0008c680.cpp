// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_0008c680 @ 0x0008c680
extern "C" int DAT_004d9968;
namespace XAPILIB { void __stdcall XLaunchNewImageA(const char *, void *); }
extern "C" void __cdecl __security_check_cookie(int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int);
struct Item { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19(); virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23(); virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27(); virtual void f28(); virtual void f29(); virtual void f30(); virtual void f31(); virtual void f32(); virtual void f33(); virtual void f34(); virtual void f35(); virtual void f36(); virtual void f37(); virtual void f38(); virtual char *f39(); };
struct Entry { Item *item; char padding[196]; };
struct Owner { char padding[8]; Entry *entries; void FUN_0008c680(int index); };
void Owner::FUN_0008c680(int index) {
  int cookie = DAT_004d9968;
  char *value = entries[index].item->f39();
  struct LaunchData { int mode; int zero; int code; int size; char rest[0xbf0]; } data;
  data.mode = 2; data.zero = 0; data.code = (signed char)*value; data.size = 4;
  XAPILIB::XLaunchNewImageA(0, &data);
  __security_check_cookie(cookie,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
}