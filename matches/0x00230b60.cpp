struct X {
    int a;
    int b;
    int c;
    int d;
    unsigned char e;
    char pad[3];
    int f;
    void Init();
};
void X::Init() {
    int* p = &b;
    a = (int)p;
    b = (int)p;
    c = (int)p;
    d = (int)p;
    e = 0;
    f = 0;
}