// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 8/8)
// FUN_0023e7a0 @ 0x0023e7a0
typedef void (*Callback)();
void FUN_0023e4d0();
void FUN_0023e4e0();
void FUN_0023e4f0();
void* __cdecl FUN_0008d690(unsigned);
inline void* __cdecl operator new(unsigned, void* p) { return p; }
struct ParamBase {
 char bytes[16]; Callback callback; unsigned tail;
 void FUN_00234960(const char*);
 void FUN_00235220(const char*);
};
namespace fight {
class StopTrack;
template<class T> struct ParamFloatConstRange {
 virtual void slot0();
 char bytes[12]; Callback callback; unsigned tail;
};
template<class T> struct ParamConditionGroup {
 virtual void slot0();
 char bytes[12]; Callback callback; unsigned tail;
};
}
extern unsigned DAT_004e5c78;
extern unsigned DAT_004e5c74;
void __cdecl FUN_002347b0(void*, void**, int);
void __cdecl FUN_0023e7a0() {
 if (!DAT_004e5c78) {
  void* items[3];
  ParamBase* a = (ParamBase*)FUN_0008d690(24);
  if(a) {
   a->FUN_00234960("timeBegin");
   fight::ParamFloatConstRange<fight::StopTrack>* p = new(a) fight::ParamFloatConstRange<fight::StopTrack>;
   p->callback = FUN_0023e4d0;
  }
  items[0]=a;
  ParamBase* b = (ParamBase*)FUN_0008d690(24);
  if(b) {
   b->FUN_00234960("timeEnd");
   fight::ParamFloatConstRange<fight::StopTrack>* p = new(b) fight::ParamFloatConstRange<fight::StopTrack>;
   p->callback = FUN_0023e4e0;
  }
  items[1]=b;
  ParamBase* c = (ParamBase*)FUN_0008d690(24);
  if(c) {
   c->FUN_00235220("conditionGroup");
   fight::ParamConditionGroup<fight::StopTrack>* p = new(c) fight::ParamConditionGroup<fight::StopTrack>;
   p->callback = FUN_0023e4f0;
  }
  items[2]=c;
  FUN_002347b0(&DAT_004e5c74,items,3);
 }
 ++DAT_004e5c78;
}
