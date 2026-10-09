class C {
  public:
    char pad[0x4c];
    int a, b, c, d, e, f;
    void Get(int* p1, int* p2, int* p3, int* p4, int* p5, int* p6);
};
void C::Get(int* p1, int* p2, int* p3, int* p4, int* p5, int* p6) {
    *p1 = a;
    *p2 = b;
    *p3 = c;
    *p4 = d;
    *p5 = e;
    *p6 = f;
}