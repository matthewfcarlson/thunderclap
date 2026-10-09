class ShadowMesh {
  public:
    int* vptr;
    ShadowMesh* vfunc_4();
};
class Helper {
  public:
    void Call(ShadowMesh*);
};
extern "C" void* __cdecl thunk_FUN_0008d690(unsigned int);
extern int vtable[];
ShadowMesh* ShadowMesh::vfunc_4() {
    ShadowMesh* p = (ShadowMesh*)thunk_FUN_0008d690(0x58);
    if (p) {
        ((Helper*)p)->Call(this);
        p->vptr = vtable;
        return p;
    }
    return 0;
}