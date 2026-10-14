// cl-flags: /O2
class X_77eb0 {
  public:
    char pad[0x30];
    int m30;
    bool Set(int v);
};

bool X_77eb0::Set(int v) {
    m30 = v;
    return true;
}
