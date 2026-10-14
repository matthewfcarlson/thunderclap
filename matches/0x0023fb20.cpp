void Helper(unsigned int* out, unsigned int x, unsigned int y, unsigned int z);
struct Obj_23fb20 {
  public:
    unsigned int value;
    unsigned short a;
    unsigned short pad;
    unsigned short b;
    void f(unsigned int a1, unsigned int a2, unsigned int a3, int a4);
};
void Obj_23fb20::f(unsigned int a1, unsigned int a2, unsigned int a3, int a4) {
    a = (unsigned short)a4;
    b = (unsigned short)a2;
    if (a4 == 0) {
        value = a1;
        return;
    }
    if (a4 == 1) {
        value = a1;
        return;
    }
    Helper(&a1, a1, a2, a3);
    value = a1;
}
