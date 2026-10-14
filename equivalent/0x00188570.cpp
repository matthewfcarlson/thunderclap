// STATUS: equivalent (tools/equiv.py level 3: 2990 inputs, branch coverage 8/8)
// FUN_00188570 @ 0x00188570
void* __cdecl FUN_0008d690(unsigned);
void __cdecl FUN_00180390();
void __cdecl FUN_001803b0();
void __cdecl FUN_001803d0();
void* operator new(unsigned, void* p) { return p; }
namespace hulkfight { namespace motion { class PropAddToMissileCountTrack; } }
struct ParamBase {
 virtual void slot0();
 char pad[12];
 void (__cdecl *callback)();
 unsigned extra;
 void FUN_00234960(const char*);
 void FUN_002348e0(const char*);
};
namespace fight {
 template<class T> struct ParamFloatConstRange: ParamBase { virtual void slot0(); };
 template<class T> struct ParamIntConstRange: ParamBase { virtual void slot0(); };
}
extern unsigned DAT_004e14d0;
extern unsigned DAT_004e14d4;
void __cdecl FUN_002347b0(unsigned*, ParamBase**, int);
void __cdecl FUN_00188570() {
 if (!DAT_004e14d4) {
  ParamBase* params[3];
  ParamBase* p=(ParamBase*)FUN_0008d690(24);
  if(p) { p->FUN_00234960("timeBegin"); new(p) fight::ParamFloatConstRange<hulkfight::motion::PropAddToMissileCountTrack>; p->callback=FUN_00180390; }
  params[0]=p;
  p=(ParamBase*)FUN_0008d690(24);
  if(p) { p->FUN_002348e0("attachmentIndex"); new(p) fight::ParamIntConstRange<hulkfight::motion::PropAddToMissileCountTrack>; p->callback=FUN_001803b0; }
  params[1]=p;
  p=(ParamBase*)FUN_0008d690(24);
  if(p) { p->FUN_002348e0("missiles"); new(p) fight::ParamIntConstRange<hulkfight::motion::PropAddToMissileCountTrack>; p->callback=FUN_001803d0; }
  params[2]=p;
  FUN_002347b0(&DAT_004e14d0,params,3);
 }
 ++DAT_004e14d4;
}
