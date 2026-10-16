struct X {
    char pad[0x18];
    unsigned char* a;
    char pad2[8];
    int* b;
    int Get(unsigned char x);
};
int X::Get(unsigned char x) {
    return b[a[x]];
}