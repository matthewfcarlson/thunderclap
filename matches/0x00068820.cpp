class C {
  public:
    bool Set(int x);
};
bool C::Set(int x) {
    *((int*)((char*)this + 0x2c)) = x;
    return true;
}