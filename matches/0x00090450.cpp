class X_90450 {
  public:
    char pad[8];
    void f();
    X_90450* target();
};
X_90450* X_90450::target() {
    f();
    ((X_90450*)((char*)this + 8))->f();
    return this;
}