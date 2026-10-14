struct Data_16f9a0 {
    int a;
    int b;
    int c;
};
class Obj_16f9a0 {
  public:
    char f(Data_16f9a0* p);
    char pad[0x1c];
    int m1c;
    int m20;
    int m24;
};
char Obj_16f9a0::f(Data_16f9a0* p) {
    m1c = p->a;
    m20 = p->b;
    m24 = p->c;
    return 1;
}
