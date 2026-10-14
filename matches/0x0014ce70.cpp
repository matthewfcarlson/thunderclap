class T {
  public:
    char pad[0x20];
    int m20;
    bool Set(int v);
};
bool T::Set(int v) {
    m20 = v;
    return true;
}
