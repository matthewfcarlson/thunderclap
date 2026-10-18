class B_3365b0 {
  public:
    int G(int);
};
class C_3365b0 {
  public:
    char pad[4];
    B_3365b0* b;
    int F(int);
    int H(int);
};
int C_3365b0::F(int param) {
    int x = b->G(param);
    return H(x);
}