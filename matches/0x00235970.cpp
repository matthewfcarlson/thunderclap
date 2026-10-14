class X_235970 {
  public:
    char pad[0xc];
    int m_val;
    bool Set(int v);
};

bool X_235970::Set(int v) {
    m_val = v;
    return true;
}
