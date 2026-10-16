class C {
  public:
    void f2(int, int*);
    void target(int);
};
void C::target(int x) {
    int y = 0;
    f2(x, &y);
}