class ShadowMesh {
  public:
    int* vptr;
    ShadowMesh* vfunc_4();
};
class ShadowSkin_2def70 {
  public:
    void Call(ShadowMesh*);
};
extern "C" void* __cdecl thunk_FUN_0008d690(unsigned int);
extern int vtable_2def70[];
ShadowMesh* ShadowMesh::vfunc_4() {
    ShadowMesh* p = (ShadowMesh*)thunk_FUN_0008d690(0x58);
    if (p) {
        ((ShadowSkin_2def70*)p)->Call(this);
        p->vptr = vtable_2def70;
        return p;
    }
    return 0;
}