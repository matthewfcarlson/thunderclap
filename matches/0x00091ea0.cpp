struct Sub {
    void Init();
};
class CUnlockableMove {
  public:
    CUnlockableMove* Ctor();
    char pad[0x49];
};
CUnlockableMove* CUnlockableMove::Ctor() {
    *(int*)this = 0x40449c;
    *((char*)this + 8) = 1;
    ((Sub*)((char*)this + 0x10))->Init();
    *(int*)((char*)this + 0x18) = 0;
    *(int*)this = 0x4044b4;
    *((char*)this + 0x20) = 0;
    *(int*)((char*)this + 0x24) = 0;
    *(int*)((char*)this + 0x28) = -1;
    *((char*)this + 0x2c) = 0;
    *((char*)this + 0x2d) = 0;
    *(int*)((char*)this + 0x30) = 0;
    ((Sub*)((char*)this + 0x38))->Init();
    ((Sub*)((char*)this + 0x40))->Init();
    *((char*)this + 0x48) = 0;
    return this;
}
