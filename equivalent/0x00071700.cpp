// STATUS: equivalent (tools/equiv.py level 3: 2989 inputs, branch coverage 8/8)
// FUN_00071700 @ 0x00071700
void* __cdecl FUN_0008d690(unsigned int);
inline void* __cdecl operator new(unsigned int, void* address) { return address; }
void __cdecl FUN_000684f0();
void __cdecl FUN_00068500();
void __cdecl FUN_00068510();
class CDamageTrack;
namespace fight {
template<class T> struct ParamFloatConstRange {
 virtual void slot0();
 char data[12];
 void (__cdecl *getter)();
 int tail;
 void FUN_00234960(const char*);
};
}
extern unsigned int DAT_004dcf74;
extern unsigned int DAT_004dcf70;
void __cdecl FUN_002347b0(unsigned int*, fight::ParamFloatConstRange<CDamageTrack>**, int);
void __cdecl FUN_00071700() {
 if (!DAT_004dcf74) {
  typedef fight::ParamFloatConstRange<CDamageTrack> Param;
  Param* params[3];
  Param* p = (Param*)FUN_0008d690(24);
  if (p) { p->FUN_00234960("timeBegin"); new(p) Param; p->getter = FUN_000684f0; }
  params[0] = p;
  p = (Param*)FUN_0008d690(24);
  if (p) { p->FUN_00234960("damage"); new(p) Param; p->getter = FUN_00068500; }
  params[1] = p;
  p = (Param*)FUN_0008d690(24);
  if (p) { p->FUN_00234960("damageMax"); new(p) Param; p->getter = FUN_00068510; }
  params[2] = p;
  FUN_002347b0(&DAT_004dcf70, params, 3);
 }
 ++DAT_004dcf74;
}
