class X {
  public:
    short data[1];
    int f(int i);
};
int X::f(int i) {
    return data[i + 3];
}