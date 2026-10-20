// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 6/6)
// FUN_002bc3d0 @ 0x002bc3d0
typedef unsigned int size_t;
void* __cdecl FUN_0008d690(size_t);
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace pure3d {
struct BillboardQuadGroupBase {
    virtual void AddRef();
    virtual void Release();
    void FUN_002a3e80();
};
struct BillboardQuadGroupLoader : BillboardQuadGroupBase {
    virtual void AddRef();
    virtual void Release();
};
struct BillboardObjectLoader {
    virtual void AddRef();
    virtual void Release();
    int a;
    int id;
    int b;
    int c;
    BillboardQuadGroupBase* group;
    BillboardObjectLoader();
};
BillboardObjectLoader::BillboardObjectLoader() : a(0), id(0x17006), b(0), c(0), group(0) {
    BillboardQuadGroupLoader* quad = (BillboardQuadGroupLoader*)FUN_0008d690(8);
    if (quad) {
        quad->FUN_002a3e80();
        new (quad) BillboardQuadGroupLoader;
        quad->AddRef();
    }
    if (group) group->Release();
    group = quad;
}
}