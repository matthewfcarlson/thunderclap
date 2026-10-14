class Sub_bc080 {
  public:
    char pad[0x10];
    int field;
};
class Obj_bc080 {
  public:
    char pad[4];
    Sub_bc080* m0;
    int Fn(int a, int b);
};
int Obj_bc080::Fn(int a, int b) {
    if (!m0)
        return -1;
    m0->field = 4;
    return 0;
}
