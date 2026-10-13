class T {
  public:
    char pad[0xc];
    int value;
    bool Set(int x);
};

bool T::Set(int x) {
    value = x;
    return true;
}
