class X {
  public:
    int Find(int);
    char Do(int, void*);
    char Fn(int, int, int, int);
};
char X::Fn(int a, int b, int c, int d) {
    int n = Find(a);
    if (n < 0)
        return 0;
    return Do(n, &b);
}