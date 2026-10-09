typedef unsigned int U;
struct Obj {
    U a, b, c, d;
    void go(U);
};
struct H {
    void run(Obj*, U*);
};
void Obj::go(U arg) {
    U temp[4];
    ((H*)arg)->run(this, temp);
    a = temp[0];
    b = temp[1];
    c = temp[2];
    d = temp[3];
}