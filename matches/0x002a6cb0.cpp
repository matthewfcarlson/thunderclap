// Same code shape as 0x002960e0 (propagated; names are from that function)
extern void* scenegraph_vftable;
void __fastcall Init(void*);
class Scenegraph {
  public:
    void* vptr;
    char pad[0x3c];
    int field40;
    Scenegraph();
};
Scenegraph::Scenegraph() {
    Init((void*)(this));
    vptr = &scenegraph_vftable;
    field40 = 0;
}