// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00052720..0x00055210 (kind game, layer game, confidence low)
#include "tree_prelude.h"


// 0x00053e30 FUN_00053e30 (192 B): equivalent/0x00053e30.cpp [isolated: compile error C2264: 'operator new' : error in function definition or declaration; function not called]
// sym: _FUN_00053e30
#include "gen/owners.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
namespace fn_f654b4fb {} using namespace fn_f654b4fb;
namespace fn_f654b4fb {
// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 6/6)
// FUN_00053e30 @ 0x00053e30

void* __cdecl FUN_0008d690(unsigned int);
void __cdecl FUN_00047fa0();
void __cdecl FUN_00047fb0();
void __cdecl FUN_002347b0(void*,void*,int);

} // namespace fn_f654b4fb
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_f654b4fb {

class CGrappleSizeCondition;
struct FUN_00234cc0 {
 FUN_00234cc0(const char*);
 virtual void slot0();
 char pad[12];
};
namespace fight {
template<class T> struct ParamEnumConstList : FUN_00234cc0 {
 void* values;
 int count;
 void (__cdecl *callback)();
 int tail;
 ParamEnumConstList(const char* s) : FUN_00234cc0(s) {}
 virtual void slot0();
};
}
extern "C" void FUN_00053e30() {
 if (!DAT_004dc4fc) {
  fight::ParamEnumConstList<CGrappleSizeCondition>* p[2];
  void* mem=FUN_0008d690((int)sizeof(fight::ParamEnumConstList<CGrappleSizeCondition>));
  if(mem) {
   int count=(*(int*)&DAT_00427760);
   p[0]=new(mem) fight::ParamEnumConstList<CGrappleSizeCondition>("compare");
   p[0]->values=((char*)&DAT_00427758); p[0]->count=count; p[0]->callback=FUN_00047fa0;
  } else p[0]=0;
  mem=FUN_0008d690((int)sizeof(fight::ParamEnumConstList<CGrappleSizeCondition>));
  if(mem) {
   int count=(*(int*)&DAT_003f5eb4);
   p[1]=new(mem) fight::ParamEnumConstList<CGrappleSizeCondition>("size");
   p[1]->values=((char*)&DAT_0048f6b4); p[1]->count=count; p[1]->callback=FUN_00047fb0;
  } else p[1]=0;
  FUN_002347b0(&DAT_004dc4f8,p,2);
 }
 ++DAT_004dc4fc;
}
} // namespace fn_f654b4fb

