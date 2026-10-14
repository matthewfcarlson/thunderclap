class X_11c030 {
  public:
    char pad[0x1c];
    int value;
    bool Set(int v);
};

bool X_11c030::Set(int v) {
    value = v;
    return true;
}
