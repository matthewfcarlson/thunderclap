class X {
  public:
    char m[0x5c];
    bool Set(int v);
};
bool X::Set(int v) {
    *(int*)((char*)this + 0x5c) = v;
    return true;
}
