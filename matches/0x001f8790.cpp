class D {
  public:
    void use_val(int);
};
class C {
    char pad[0x44c];
    int value;

  public:
    C* get_obj();
    void f(int);
};
void C::f(int p) {
    D* q = (D*)get_obj();
    q->use_val(value);
    value = p;
}