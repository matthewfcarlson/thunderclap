// Same code shape as 0x002b50c0 (propagated; names are from that function)
typedef unsigned char byte;
void thunk(void*);
void thunk_val(unsigned int);
extern void* shadow_vftable;
extern void* ref_vftable;
namespace pure3d {
class ShadowMeshVertices {
public:
    virtual void f0();
    virtual void f1();
    virtual ShadowMeshVertices* vfunc_2(byte);
    char pad[0x10 - 4];
};
ShadowMeshVertices* ShadowMeshVertices::vfunc_2(byte param) {
    *(void**)this = &shadow_vftable;
    thunk_val(*(unsigned int*)((char*)this + 0x10));
    thunk_val(*(unsigned int*)((char*)this + 0x14));
    *(void**)this = &ref_vftable;
    if (param & 1) thunk(this);
    return this;
}
}
