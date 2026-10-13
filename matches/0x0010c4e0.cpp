class T {
  public:
    char pad[0x10];
    int m10;
    bool Set(int x);
};

bool T::Set(int x) {
    m10 = x;
    return true;
}
