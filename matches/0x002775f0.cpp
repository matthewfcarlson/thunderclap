class X {
  public:
    int data[4];
    int value;
    void f(int i);
};
void X::f(int i) {
    value = data[i];
}