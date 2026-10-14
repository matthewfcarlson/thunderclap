class Obj_1ca040 {
  public:
    Obj_1ca040* f(int, int);
    void helper(int, int, int);
};
Obj_1ca040* Obj_1ca040::f(int a, int b) {
    helper(12, a, b);
    return this;
}