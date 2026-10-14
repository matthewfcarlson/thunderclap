struct T_294620 {
    int x, y, z;
};
class C_294620 {
  public:
    void Prep(int* a, T_294620* out);
    void Finish(T_294620 t, int d, int e);
    void Target(int a, int b, int c, int d, int e);
};
void C_294620::Target(int a, int b, int c, int d, int e) {
    T_294620 t;
    Prep(&a, &t);
    Finish(t, d, e);
}
