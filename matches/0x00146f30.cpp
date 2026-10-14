class Obj_146f30 {
  public:
    char pad[0x34];
    bool Set(char a);
};

bool Obj_146f30::Set(char a) {
    *(char*)((char*)this + 0x34) = a;
    return true;
}
