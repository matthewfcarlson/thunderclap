class FEObject {
  public:
    char pad[0x118];
};
class MapThing : public FEObject {
  public:
    int vfunc_12();
};
int MapThing::vfunc_12() {
    return *(int*)((char*)this + 0x118);
}