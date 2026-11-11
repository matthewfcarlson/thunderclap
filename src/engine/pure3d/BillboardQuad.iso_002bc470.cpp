// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002b87d0..0x002bd430 (kind game, layer engine, confidence high), dominant class pure3d::BillboardQuad
#include "tree_prelude.h"


// 0x002bc470 FUN_002bc470 (96 B): equivalent/0x002bc470.cpp [isolated: compile error C2084: function 'void *operator new(size_t,void *)' already has a body]
// sym: ??0OldBillboardObjectLoader@pure3d@fn_f5b05fca@@QAE@XZ @ec6c6099223c @wd47526f9df0c
namespace fn_f5b05fca {} using namespace fn_f5b05fca;
namespace fn_f5b05fca {
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 6/6)
// FUN_002bc470 @ 0x002bc470

} // namespace fn_f5b05fca
inline void* operator new(size_t, void* p) { return p; }
namespace fn_f5b05fca {

extern "C" void* __cdecl FUN_0008d690(unsigned int);
namespace pure3d {
struct QuadBase { virtual void AddRef(); virtual void Release(); void FUN_002a3e80(); };
struct OldBillboardQuadGroupLoader : QuadBase { virtual void AddRef(); virtual void Release(); OldBillboardQuadGroupLoader() {} };
struct OldBillboardObjectLoader { virtual void AddRef(); virtual void Release(); unsigned int count; unsigned int type; unsigned int fieldC; unsigned int field10; QuadBase* loader; OldBillboardObjectLoader(); };
OldBillboardObjectLoader::OldBillboardObjectLoader() : count(0), type(0x17002), fieldC(0), field10(0), loader(0) {
 OldBillboardQuadGroupLoader* quad = (OldBillboardQuadGroupLoader*)FUN_0008d690(8);
 if (quad) {
  quad->FUN_002a3e80();
  new(quad) OldBillboardQuadGroupLoader;
  quad->AddRef();
 }
 if (loader) loader->Release();
 loader = quad;
}
}
} // namespace fn_f5b05fca

