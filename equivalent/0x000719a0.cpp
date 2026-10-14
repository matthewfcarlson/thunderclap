// STATUS: equivalent (tools/equiv.py level 3: 2990 inputs, branch coverage 8/8)
// FUN_000719a0 @ 0x000719a0
void* __cdecl FUN_0008d690(unsigned);
void __cdecl FUN_00068580();
void __cdecl FUN_00068590();
void __cdecl FUN_000685a0();
extern unsigned DAT_004dcf8c;
extern unsigned DAT_004dcf88;
inline void* __cdecl operator new(unsigned, void* p) { return p; }
struct Base_719a0 {
 virtual void slot0();
 char pad[12];
 void (__cdecl *callback)();
 unsigned tail;
 void FUN_00234960(const char*);
};
class CInvincibleTrack;
namespace fight {
template<class T> struct ParamFloatConstRange : Base_719a0 {
 virtual void slot0();
};
}
void __cdecl FUN_002347b0(unsigned*, Base_719a0**, int);
void __cdecl FUN_000719a0() {
 if (!DAT_004dcf8c) {
 Base_719a0* list[3];
 const char* names[3] = {"timeBegin", "timeEnd", "extensionTime"};
 void (__cdecl *callbacks[3])() = {FUN_00068580,FUN_00068590,FUN_000685a0};
 for (int i=0;i<3;++i) {
  Base_719a0* p = (Base_719a0*)FUN_0008d690(24);
  if(p) {
   p->FUN_00234960(names[i]);
   new(p) fight::ParamFloatConstRange<CInvincibleTrack>;
   p->callback=callbacks[i];
  }
  list[i]=p;
 }
 FUN_002347b0(&DAT_004dcf88,list,3);
 }
 ++DAT_004dcf8c;
}
