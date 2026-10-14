struct S3 {
    int a;
    int b;
    int c;
};

struct T {
    char pad[0x30];
    int m30;
    int m34;
    int m38;
    bool m3c;
    bool Set(S3* p);
};

bool T::Set(S3* p) {
    m30 = p->a;
    m34 = p->b;
    m38 = p->c;
    return true;
}
