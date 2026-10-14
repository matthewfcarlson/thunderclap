class Obj_1659e0 {
  public:
    bool Set(int x);
};
bool Obj_1659e0::Set(int x) {
    *(int*)((char*)this + 0x10) = x;
    return true;
}
