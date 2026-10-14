class Obj_29dcc0 {
  public:
    char pad[0x18];
    int field;
    char pad2[0x0c];
    char flag;
    float A(int, int);
    float B(int, int);
    float C(int, int);
    float D(int, int);
    float F(int, int);
};
float Obj_29dcc0::F(int a, int b) {
    field = 0;
    float r = A(a, b);
    r = r + B(a, b);
    r = r + C(a, b);
    if (flag)
        return D(a, b) + r;
    return r;
}