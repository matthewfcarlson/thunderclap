class Obj {
  public:
    bool Set(int x);
};
bool Obj::Set(int x) {
    *(int*)((char*)this + 0x10) = x;
    return true;
}
