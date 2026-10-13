class X {
  public:
    bool F(int a);
};
bool X::F(int a) {
    *(int*)((char*)this + 0xc) = a;
    return true;
}