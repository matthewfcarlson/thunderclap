class Function {
  public:
    virtual void f();
    int a;
    int b;
    int c;
    Function(int x, int y);
};
Function::Function(int x, int y) {
    a = x;
    c = y;
    b = 0;
}