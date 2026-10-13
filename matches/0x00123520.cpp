class X {
  public:
    char Fn(int a);
    char pad[0x10];
    int m_10;
};

char X::Fn(int a) {
    m_10 = a;
    return 1;
}