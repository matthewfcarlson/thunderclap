class Obj {
  public:
    char pad[0x24];
    bool Set(int v);
};

bool Obj::Set(int v) {
    *(int*)((char*)this + 0x24) = v;
    return true;
}
