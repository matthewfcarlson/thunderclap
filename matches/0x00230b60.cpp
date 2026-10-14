struct X_230b60 {
    int a;
    int b;
    int c;
    int d;
    unsigned char e;
    char pad[3];
    int f;
    void Init();
};
void X_230b60::Init() {
    int* p = &b;
    a = (int)p;
    b = (int)p;
    c = (int)p;
    d = (int)p;
    e = 0;
    f = 0;
}