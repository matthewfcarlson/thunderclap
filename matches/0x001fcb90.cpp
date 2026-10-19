struct Obj {
    char pad[0xcd];
    unsigned char a;
    unsigned char b;
};
struct ThisWrap_001fcb90 {
    Obj* Find(int);
    unsigned char FUN_001fcb90(int n);
};
unsigned char ThisWrap_001fcb90::FUN_001fcb90(int n) {
    Obj* p = this->Find(n);
    if (p && p->b && p->a)
        return 1;
    return 0;
}