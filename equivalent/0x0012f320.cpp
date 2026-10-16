// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 30/30)
// hulkfight::LocationCondition::vfunc_6 @ 0x0012f320
#include "decls/address.h"
#include "decls/data/game/global.h"
struct NameSource_12f320 { const char* FUN_000897e0(); };
struct Manager_12f320 { NameSource_12f320* FUN_00086310(); };
struct World { char pad[0x54]; Manager_12f320* manager; };
extern "C" int __cdecl strncmp(const char*, const char*, unsigned int);
extern "C" char* __cdecl strrchr(const char*, int);
namespace hulkfight {
struct LocationCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(int,int,int);
 char pad[8]; int prefixMode; const char* prefix; int suffixMode; const char* suffix;
};
bool LocationCondition::vfunc_6(int,int,int) {
 const char* name = DAT_004dd700->manager->FUN_00086310()->FUN_000897e0();
 if (!name) name = ((const char*)&DAT_003f335c);
 if (prefixMode != 2) {
  const char* p = prefix ? prefix : ((const char*)&DAT_003f335c);
  unsigned int n=0; while(p[n]) ++n;
  int result = strncmp(name,p,n);
  if (result ? prefixMode == 0 : prefixMode != 0) return false;
 }
 if (suffixMode != 2) {
  const char* tail = strrchr(name,'_');
  if (!tail) tail = ((const char*)&DAT_003f335c);
  else if (*tail) ++tail;
  const char* p = suffix ? suffix : ((const char*)&DAT_003f335c);
  unsigned int n=0; while(p[n]) ++n;
  int result = strncmp(tail,p,n);
  if (result ? suffixMode == 0 : suffixMode != 0) return false;
 }
 return true;
}
}