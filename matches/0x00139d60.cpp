class X_139d60 {
  public:
    char pad[0x40];
    int m;
    bool Set(int v);
};

bool X_139d60::Set(int v) {
    m = v;
    return true;
}
