class X_5d590 {
  public:
    bool Set(int v);
};
bool X_5d590::Set(int v) {
    *((int*)((char*)this + 0x44)) = v;
    return true;
}
