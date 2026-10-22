class CSPManager_1df1e0 {
  public:
    int Find(int);
    char Do(int, void*);
    char Fn(int, int, int, int);
};
char CSPManager_1df1e0::Fn(int a, int b, int c, int d) {
    int n = Find(a);
    if (n < 0)
        return 0;
    return Do(n, &b);
}