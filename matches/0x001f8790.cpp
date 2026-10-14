class D {
  public:
    void use_val(int);
};
class C_1f8790 {
    char pad[0x44c];
    int value;

  public:
    C_1f8790* get_obj();
    void f(int);
};
void C_1f8790::f(int p) {
    D* q = (D*)get_obj();
    q->use_val(value);
    value = p;
}