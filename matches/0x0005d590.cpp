class X {
  public:
    bool Set(int v);
};
bool X::Set(int v) {
    *((int*)((char*)this + 0x44)) = v;
    return true;
}
