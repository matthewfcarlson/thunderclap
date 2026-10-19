extern void* scenegraph_vftable;
struct Ctor_002a3480 {
    Ctor_002a3480();
};
class Scenegraph : public Ctor_002a3480 {
  public:
    void* vptr;
    char pad[0x3c];
    int field40;
    Scenegraph();
};
Scenegraph::Scenegraph() : Ctor_002a3480() {
    vptr = &scenegraph_vftable;
    field40 = 0;
}