// Same code shape as 0x002b50c0 (propagated; names are from that function)
typedef unsigned char byte_2b5200;
void thunk(void*);
void thunk_val(unsigned int);
extern void* shadow_vftable;
extern void* ref_vftable_2b5200;
namespace pure3d {
class ShadowMeshVertices {
  public:
    virtual void f0();
    virtual void f1();
    virtual ShadowMeshVertices* vfunc_2(byte_2b5200);
    char pad[0x10 - 4];
};
ShadowMeshVertices* ShadowMeshVertices::vfunc_2(byte_2b5200 param) {
    *(void**)this = &shadow_vftable;
    thunk_val(*(unsigned int*)((char*)this + 0x10));
    thunk_val(*(unsigned int*)((char*)this + 0x14));
    *(void**)this = &ref_vftable_2b5200;
    if (param & 1)
        thunk(this);
    return this;
}
} // namespace pure3d
