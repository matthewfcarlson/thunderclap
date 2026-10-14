class X_11baf0 {
  public:
    char pad[0x14];
    int m14;
    bool Set(int v);
};

bool X_11baf0::Set(int v) {
    m14 = v;
    return true;
}
