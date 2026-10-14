class C_68820 {
  public:
    bool Set(int x);
};
bool C_68820::Set(int x) {
    *((int*)((char*)this + 0x2c)) = x;
    return true;
}