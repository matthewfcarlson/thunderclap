// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 8/8)
// FUN_00075b50 @ 0x00075b50
void* __cdecl FUN_0008d690(unsigned int);
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
void __cdecl FUN_00068b40();
void __cdecl FUN_00068b50();
void __cdecl FUN_00068b60();
extern int DAT_004dd00c;
extern int DAT_004dd008;
struct ParamBase_75b50 {
 virtual void slot0();
 char reserved[12];
 void (__cdecl *callback)();
 int tail;
 void FUN_00234960(const char*);
 void FUN_00234a90(const char*);
};
class CAIHintTrack;
namespace fight {
 template<class T> struct ParamFloatConstRange : ParamBase_75b50 { virtual void slot0(); };
 template<class T> struct ParamName : ParamBase_75b50 { virtual void slot0(); };
}
void __cdecl FUN_002347b0(int*, ParamBase_75b50**, int);
void __cdecl FUN_00075b50() {
 if (DAT_004dd00c == 0) {
  ParamBase_75b50* params[3];
  ParamBase_75b50* p = (ParamBase_75b50*)FUN_0008d690(24);
  if(p) {
   p->FUN_00234960("timeBegin");
   new(p) fight::ParamFloatConstRange<CAIHintTrack>;
   p->callback = FUN_00068b40;
  }
  params[0]=p;
  p=(ParamBase_75b50*)FUN_0008d690(24);
  if(p) {
   p->FUN_00234960("timeEnd");
   new(p) fight::ParamFloatConstRange<CAIHintTrack>;
   p->callback=FUN_00068b50;
  }
  params[1]=p;
  p=(ParamBase_75b50*)FUN_0008d690(24);
  if(p) {
   p->FUN_00234a90("hint");
   new(p) fight::ParamName<CAIHintTrack>;
   p->callback=FUN_00068b60;
  }
  params[2]=p;
  FUN_002347b0(&DAT_004dd008,params,3);
 }
 ++DAT_004dd00c;
}
