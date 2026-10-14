struct Helper_bbfd0 {
    int F();
};
class Obj_bbfd0 {
  public:
    char pad[4];
    Helper_bbfd0* m;
    int Fn(int a, int b);
};
int Obj_bbfd0::Fn(int a, int b) {
    if (m == 0)
        return -1;
    m->F();
    return 0;
}
