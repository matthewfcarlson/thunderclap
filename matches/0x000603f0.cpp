class T {
    char pad[0xc4];
    int m;

  public:
    bool Set(int x);
};
bool T::Set(int x) {
    m = x;
    return true;
}
