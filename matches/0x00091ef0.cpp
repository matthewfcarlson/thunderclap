class Obj {
  public:
    void dtor();
};
void rel(void*);
class CUnlockableMove {
  public:
    int vf;
    char pad[0x14];
    void* ptr;
    char rest[0x24];
    void dtor();
};
void CUnlockableMove::dtor() {
    vf = 0x4044b4;
    ((Obj*)((char*)this + 0x40))->dtor();
    ((Obj*)((char*)this + 0x38))->dtor();
    vf = 0x40449c;
    if (ptr) {
        rel(ptr);
        ptr = 0;
    }
    ((Obj*)((char*)this + 0x10))->dtor();
}
