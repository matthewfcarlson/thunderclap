extern void* scenegraph_vftable;
void Init();
class Scenegraph {
  public:
    void* vptr;
    char pad[0x3c];
    int field40;
    Scenegraph();
};
Scenegraph::Scenegraph() {
    Init();
    vptr = &scenegraph_vftable;
    field40 = 0;
}