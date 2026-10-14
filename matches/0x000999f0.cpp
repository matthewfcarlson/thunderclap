struct Obj {
    void G();
};
class T {
  public:
    char pad[0xc4];
    Obj* p;
    void Target();
};
void T::Target() {
    ((Obj*)((char*)p + 0x250))->G();
}
