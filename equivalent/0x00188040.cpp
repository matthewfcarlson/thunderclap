// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 10/10)
// FUN_00188040 @ 0x00188040
void* __cdecl operator new(unsigned int, void* p) { return p; }
extern void* __cdecl FUN_0008d690(unsigned int);
extern void __cdecl FUN_0017f890();
extern void __cdecl FUN_0017f8b0();
extern void __cdecl FUN_0017f8d0();
extern void __cdecl FUN_0017f8f0();
namespace hulkfight { namespace motion { class GrapplePropDamageTrack; } }
struct ParamBase {
 virtual void slot0();
 char pad[12];
 void (__cdecl *callback)();
 unsigned int tail;
 void FUN_00234960(const char*);
 void FUN_002348e0(const char*);
};
namespace fight {
template<class T> struct ParamFloatConstRange : ParamBase { virtual void slot0(); };
template<class T> struct ParamIntConstRange : ParamBase { virtual void slot0(); };
}
extern unsigned int DAT_004e1494;
extern unsigned int DAT_004e1490;
extern void __cdecl FUN_002347b0(void*, ParamBase**, int);
void __cdecl FUN_00188040() {
 if (!DAT_004e1494) {
  ParamBase* params[4];
  ParamBase* p = (ParamBase*)FUN_0008d690(24);
  if(p) { p->FUN_00234960("timeBegin"); new(p) fight::ParamFloatConstRange<hulkfight::motion::GrapplePropDamageTrack>; p->callback=FUN_0017f890; }
  params[0]=p;
  p=(ParamBase*)FUN_0008d690(24);
  if(p) { p->FUN_002348e0("attachmentIndex"); new(p) fight::ParamIntConstRange<hulkfight::motion::GrapplePropDamageTrack>; p->callback=FUN_0017f8b0; }
  params[1]=p;
  p=(ParamBase*)FUN_0008d690(24);
  if(p) { p->FUN_00234960("damage"); new(p) fight::ParamFloatConstRange<hulkfight::motion::GrapplePropDamageTrack>; p->callback=FUN_0017f8d0; }
  params[2]=p;
  p=(ParamBase*)FUN_0008d690(24);
  if(p) { p->FUN_00234960("damageMax"); new(p) fight::ParamFloatConstRange<hulkfight::motion::GrapplePropDamageTrack>; p->callback=FUN_0017f8f0; }
  params[3]=p;
  FUN_002347b0(&DAT_004e1490,params,4);
 }
 ++DAT_004e1494;
}