// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00232c40..0x00234090 (kind game, layer engine, confidence high), dominant class fight::Branch
// (tree_prelude.h: not needed)


// 0x00233fe0 FUN_00233fe0 (175 B): equivalent/0x00233fe0.cpp [isolated: code differs from its standalone build]
// sym: ?FUN_00233fe0@Handle_233fe0@fn_ff64c792@@QAE_NPAUSource_233fe0@2@@Z
#include "gen/owners.h"
namespace fn_ff64c792 {} using namespace fn_ff64c792;
namespace fn_ff64c792 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 26/28, incomplete)
// FUN_00233fe0 @ 0x00233fe0
struct Item_233fe0 {
 virtual void AddRef() = 0;
 virtual void Release() = 0;
};
struct Source_233fe0 {
 Item_233fe0* FUN_00233650(unsigned key);
};
struct Handle_233fe0 {
 Item_233fe0* object;
 unsigned key;
 int index;
 void FUN_00233ef0(Source_233fe0* source, Item_233fe0* object);
 bool FUN_00233fe0(Source_233fe0* source);
};
bool Handle_233fe0::FUN_00233fe0(Source_233fe0* source) {
 if (object) return true;
 if (!source) return false;
 if (key) {
  Item_233fe0* found = source->FUN_00233650(key);
  if (found) found->AddRef();
  if (object) object->Release();
  object = found;
 } else if (index >= 0) {
  Item_233fe0* current = ((Item_233fe0 *)((owners::Node_232f60 *)source)->FUN_00232f60());
  if (!current) return false;
  int remaining = index;
  while (remaining > 0) {
   current = ((Item_233fe0 *)((owners::Node_232fe0 *)current)->FUN_00232fe0());
   --remaining;
   if (!current) break;
  }
  FUN_00233ef0(source, current);
 }
 return object != 0 || (key == 0 && index < 0);
}
} // namespace fn_ff64c792

