struct Obj {
    char pad[0x1c9];
    unsigned char a;
    char pad2[0x1fc - 0x1ca];
    int b;
    int f();
};
int Obj::f() {
    if (a && b)
        return 1;
    return 0;
}