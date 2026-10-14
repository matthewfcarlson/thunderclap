class Obj_1a22a0 {
  public:
    bool Set(int x);
};
bool Obj_1a22a0::Set(int x) {
    *(int*)((char*)this + 0x44) = x;
    return true;
}
