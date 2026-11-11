// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00335270..0x00338d90 (kind game, layer engine, confidence medium), dominant class movie::BinkCallback
// (tree_prelude.h: not needed)


// 0x00336f30 FUN_00336f30 (212 B): equivalent/0x00336f30.cpp [isolated: code differs from its standalone build]
// sym: ?initialize@Target_336f30@fn_ffce5e15@@QAEXPAUSource_336f30@2@E@Z @e2ee02eca155 @w99063e6ec5c0
#include "gen/owners.h"
#include "decls/data/engine/movie.h"
namespace fn_ffce5e15 {} using namespace fn_ffce5e15;
namespace fn_ffce5e15 {
// STATUS: equivalent (tools/equiv.py level 3: 2438 inputs, branch coverage 18/18)
// FUN_00336f30 @ 0x00336f30

struct Allocator {  void* FUN_00337d60(unsigned int size, int alignment); };
struct Entry_336f30 { int unknown; const char* name; int type;  };
struct Source_336f30 { char pad[0x44]; int count;  };
struct Target_336f30 { int unknown; Source_336f30* source; void** items; int state; void FUN_003353e0(int, Entry_336f30*); void initialize(Source_336f30*, unsigned char); };
void Target_336f30::initialize(Source_336f30* input, unsigned char skip) {
 ((owners::A_337d50 *)&((*(Allocator*)&DAT_0055dbb0)))->FUN_00337d50();
 state=0; source=input;
 items=(void**)(*(Allocator*)&DAT_0055dbb0).FUN_00337d60((unsigned int)input->count*4,4);
 for(int i=0;i<input->count;++i) {
  Entry_336f30* entry=((Entry_336f30 *)((owners::Thing_337090 *)input)->FUN_00337090(i));
  bool match=false;
  if(skip) {
   const char* a=entry->name; const char* b="MayaCreateFunction";
   int j=0; for(;j<19;++j) { if(a[j]!=b[j]) break; }
   match=(j==19);
  }
  items[i]=0;
  if(!match) {
   if(entry->type>=4 && entry->type<=8) {
    int bytes=((int)((owners::Value_337f80 *)entry)->FUN_00337f80());
    items[i]=(*(Allocator*)&DAT_0055dbb0).FUN_00337d60(bytes,4);
   }
   FUN_003353e0(i,entry);
  }
 }
}
} // namespace fn_ffce5e15

