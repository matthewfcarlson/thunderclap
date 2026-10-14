// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 8/8)
// FUN_001382f0 @ 0x001382f0
typedef unsigned int size_t;
inline void* __cdecl operator new(size_t, void* p) { return p; }
extern void* __cdecl FUN_0008d690(unsigned int);
extern void __cdecl FUN_00133470();
extern void __cdecl FUN_00133480();
extern void __cdecl FUN_001334a0();
struct FloatBase {
 virtual void slot0();
 char data[12];
 void (__cdecl *callback)();
 int tail;
 FloatBase(const char*); // equiv-name: FUN_00234960
};
struct IntBase {
 virtual void slot0();
 char data[12];
 void (__cdecl *callback)();
 int tail;
 IntBase(const char*); // equiv-name: FUN_002348e0
};
namespace hulkfight { namespace motion { class HoverTrack; } }
namespace fight {
template<class T> struct ParamFloatConstRange : FloatBase {
 ParamFloatConstRange(const char* s) : FloatBase(s) {}
 virtual void slot0();
};
template<class T> struct ParamIntConstRange : IntBase {
 ParamIntConstRange(const char* s) : IntBase(s) {}
 virtual void slot0();
};
}
extern int DAT_004e0eec;
extern int DAT_004e0ee8;
extern void __cdecl FUN_002347b0(int*, void**, int);
void __cdecl FUN_001382f0() {
 if (!DAT_004e0eec) {
  void* entries[3];
  typedef fight::ParamFloatConstRange<hulkfight::motion::HoverTrack> F;
  typedef fight::ParamIntConstRange<hulkfight::motion::HoverTrack> I;
  void* p=FUN_0008d690(24);
  F* a = p ? new (p) F("timeBegin") : 0;
  if(a) a->callback=FUN_00133470;
  entries[0]=a;
  p=FUN_0008d690(24);
  F* b = p ? new (p) F("timeEnd") : 0;
  if(b) b->callback=FUN_00133480;
  entries[1]=b;
  p=FUN_0008d690(24);
  I* c = p ? new (p) I("groundFixup") : 0;
  if(c) c->callback=FUN_001334a0;
  entries[2]=c;
  FUN_002347b0(&DAT_004e0ee8,entries,3);
 }
 ++DAT_004e0eec;
}