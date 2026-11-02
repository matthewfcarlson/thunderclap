// Same code shape as 0x002960e0 (propagated; names are from that function)
extern void* scenegraph_vftable;
extern "C" void __fastcall FUN_00284cd0(void*);
class BillboardQuadGroupAnimationController_2a9760 {
  public:
    void* vptr;
    char pad[0x3c];
    int field40;
    BillboardQuadGroupAnimationController_2a9760();
};
BillboardQuadGroupAnimationController_2a9760::BillboardQuadGroupAnimationController_2a9760() {
    FUN_00284cd0((void*)(this));
    vptr = &scenegraph_vftable;
    field40 = 0;
}