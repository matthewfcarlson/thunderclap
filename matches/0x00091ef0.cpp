extern "C" char DAT_0040449c[];
extern "C" char DAT_004044b4[];
class Obj_91ef0 {
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
    vf = ((int)DAT_004044b4);
    ((Obj_91ef0*)((char*)this + 0x40))->dtor();
    ((Obj_91ef0*)((char*)this + 0x38))->dtor();
    vf = ((int)DAT_0040449c);
    if (ptr) {
        rel(ptr);
        ptr = 0;
    }
    ((Obj_91ef0*)((char*)this + 0x10))->dtor();
}
