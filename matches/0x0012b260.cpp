class T {
  public:
    char pad[12];
    int m;
    bool Set(int x);
};

bool T::Set(int x) {
    m = x;
    return true;
}
