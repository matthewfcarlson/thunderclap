class X {
  public:
    char pad[0xc];
    int m_val;
    bool Set(int v);
};

bool X::Set(int v) {
    m_val = v;
    return true;
}
