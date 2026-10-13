class T {
  public:
    char pad[0x54];
    int m54;
    bool Set(int v);
};

bool T::Set(int v) {
    m54 = v;
    return true;
}
