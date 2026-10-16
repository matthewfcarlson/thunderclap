class X {
  public:
    int a;
    int b;
    int fn(int x, int y);
    void other();
};
int X::fn(int x, int y) {
    if (!b)
        return -1;
    other();
    return 0;
}