class X_11c1e0 {
  public:
    char m[0x5c];
    bool Set(int v);
};
bool X_11c1e0::Set(int v) {
    *(int*)((char*)this + 0x5c) = v;
    return true;
}
