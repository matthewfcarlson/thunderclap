// Same code shape as 0x00021650 (propagated; names are from that function)
typedef unsigned int u32_bebf0;
extern const int type_animation;
extern const int type_refcount;
extern void __cdecl Cast(u32_bebf0, int, const int*, const int*, int);
class DynamicCaster {
  public:
    virtual void vfunc_0(void*);
};
void DynamicCaster::vfunc_0(void* p) {
    Cast((u32_bebf0)p, 0, &type_refcount, &type_animation, 0);
}