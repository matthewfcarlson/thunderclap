struct Src {
    int a;
    int b;
    int c;
};
struct Tgt {
    char pad[0x80];
    int x;
    int y;
    int z;
    char Set(Src* s);
};
char Tgt::Set(Src* s) {
    x = s->a;
    y = s->b;
    z = s->c;
    return 1;
}
