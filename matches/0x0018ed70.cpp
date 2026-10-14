struct S3_18ed70 {
    int a;
    int b;
    int c;
};

struct T_18ed70 {
    char pad[0x30];
    int m30;
    int m34;
    int m38;
    bool m3c;
    bool Set(S3_18ed70* p);
};

bool T_18ed70::Set(S3_18ed70* p) {
    m30 = p->a;
    m34 = p->b;
    m38 = p->c;
    return true;
}
