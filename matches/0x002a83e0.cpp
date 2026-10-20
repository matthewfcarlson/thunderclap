// Same code shape as 0x002960e0 (propagated; names are from that function)
extern void* scenegraph_vftable;
void __fastcall Init(void*);
class ShaderAnimationController_2a83e0 {
  public:
    void* vptr;
    char pad[0x3c];
    int field40;
    ShaderAnimationController_2a83e0();
};
ShaderAnimationController_2a83e0::ShaderAnimationController_2a83e0() {
    Init((void*)(this));
    vptr = &scenegraph_vftable;
    field40 = 0;
}