struct S_61e80 {
    int a, b, c;
};
struct T_61e80 {
    char pad[16];
    S_61e80 s;
    bool operator=(const S_61e80* p_61e80);
};
bool T_61e80::operator=(const S_61e80* p_61e80) {
    s.a = p_61e80->a;
    s.b = p_61e80->b;
    s.c = p_61e80->c;
    return true;
}