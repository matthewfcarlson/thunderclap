typedef unsigned char byte_2b50c0;
void thunk(void*);
void thunk_val(unsigned int);
extern void* shadow_vftable;
extern void* ref_vftable_2b50c0;
namespace pure3d {
class ShadowMeshVertices {
  public:
    virtual void f0();
    virtual void f1();
    virtual ShadowMeshVertices* vfunc_2(byte_2b50c0);
    char pad[0x10 - 4];
};
ShadowMeshVertices* ShadowMeshVertices::vfunc_2(byte_2b50c0 param) {
    *(void**)this = &shadow_vftable;
    thunk_val(*(unsigned int*)((char*)this + 0x10));
    thunk_val(*(unsigned int*)((char*)this + 0x14));
    *(void**)this = &ref_vftable_2b50c0;
    if (param & 1)
        thunk(this);
    return this;
}
} // namespace pure3d
