class Obj {
  public:
    char pad[0x34];
    bool Set(char a);
};

bool Obj::Set(char a) {
    *(char*)((char*)this + 0x34) = a;
    return true;
}
