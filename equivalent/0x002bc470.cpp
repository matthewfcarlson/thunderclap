// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 6/6)
// FUN_002bc470 @ 0x002bc470
inline void* operator new(unsigned int, void* p) { return p; }
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
