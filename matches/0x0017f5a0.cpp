class Obj {
  public:
    bool Set(int x);
    char pad[12];
    int m_field;
};

bool Obj::Set(int x) {
    m_field = x;
    return true;
}
