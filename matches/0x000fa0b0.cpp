struct Data {
    unsigned int a, b, c, d;
    unsigned char x, y;
};
struct Source {
    char pad[4];
    unsigned int a, b, c, d;
    unsigned char byte0, byte1;
    Data FUN_000fa0b0();
};
Data Source::FUN_000fa0b0() {
    Data t;
    t.a = a;
    t.b = b;
    t.c = c;
    t.d = d;
    t.x = byte1;
    t.y = byte0;
    return t;
}