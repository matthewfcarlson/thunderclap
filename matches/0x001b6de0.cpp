class C_1b6de0 {
  public:
    int a[6];
    void f(int x);
};
void C_1b6de0::f(int x) {
    int i = 0;
    do {
        if (a[i * 2] == x) {
            a[i * 2] = 0;
            return;
        }
        ++i;
    } while (i < 3);
}