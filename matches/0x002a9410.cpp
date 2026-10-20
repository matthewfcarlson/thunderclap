// Same code shape as 0x002960e0 (propagated; names are from that function)
extern void* scenegraph_vftable;
void __fastcall Init(void*);
class TextureAnimationController_2a9410 {
  public:
    void* vptr;
    char pad[0x3c];
    int field40;
    TextureAnimationController_2a9410();
};
TextureAnimationController_2a9410::TextureAnimationController_2a9410() {
    Init((void*)(this));
    vptr = &scenegraph_vftable;
    field40 = 0;
}