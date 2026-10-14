class C_1ca020 {
  public:
    void callee(int, int, int);
    C_1ca020* wrap(int, int);
};
C_1ca020* C_1ca020::wrap(int a, int b) {
    callee(11, a, b);
    return this;
}
