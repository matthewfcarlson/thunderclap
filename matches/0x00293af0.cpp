class C_293af0 {
    char pad[0xcc];

  public:
    unsigned char flag;
    char pad2[3];
    int a, b, c;
    void f(int* p);
};
void C_293af0::f(int* p) {
    a = p[0];
    b = p[1];
    c = p[2];
    flag = 0;
}