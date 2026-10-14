class X {
  public:
    char pad[0x7c];
    int m7c;
    bool Set(int v);
};

bool X::Set(int v) {
    m7c = v;
    return true;
}
