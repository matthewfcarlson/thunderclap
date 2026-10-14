// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 8/8)
// FUN_00156030 @ 0x00156030
void* __cdecl FUN_0008d690(unsigned int);
void __cdecl FUN_0014cce0();
void __cdecl FUN_0014ccf0();
void __cdecl FUN_0014cd10();
extern int DAT_004e1104;
extern int DAT_004e1100;
void __cdecl FUN_002347b0(void*, void*, int);
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
namespace hulkfight { namespace motion { class InterruptPriorityTrack; } }
namespace fight {
template<class T> struct ParamFloatConstRange {
 virtual void slot0();
 char pad[12];
 void (__cdecl *callback)();
 int tail;
 void FUN_00234960(const char*);
};
template<class T> struct ParamIntConstRange {
 virtual void slot0();
 char pad[12];
 void (__cdecl *callback)();
 int tail;
 void FUN_002348e0(const char*);
};
}
void __cdecl FUN_00156030() {
 if (!DAT_004e1104) {
  void* params[3];
  typedef fight::ParamFloatConstRange<hulkfight::motion::InterruptPriorityTrack> FloatParam;
  typedef fight::ParamIntConstRange<hulkfight::motion::InterruptPriorityTrack> IntParam;
  FloatParam* a = (FloatParam*)FUN_0008d690(24);
  if(a) { a->FUN_00234960("timeBegin"); new(a) FloatParam; a->callback = FUN_0014cce0; }
  params[0]=a;
  FloatParam* b = (FloatParam*)FUN_0008d690(24);
  if(b) { b->FUN_00234960("timeEnd"); new(b) FloatParam; b->callback = FUN_0014ccf0; }
  params[1]=b;
  IntParam* c = (IntParam*)FUN_0008d690(24);
  if(c) { c->FUN_002348e0("interruptPriority"); new(c) IntParam; c->callback = FUN_0014cd10; }
  params[2]=c;
  FUN_002347b0(&DAT_004e1100,params,3);
 }
 ++DAT_004e1104;
}