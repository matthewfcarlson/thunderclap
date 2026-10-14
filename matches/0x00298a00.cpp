class X_298a00 {
  public:
    char pad0[8];
    unsigned char count;
    char pad9[3];
    unsigned char* map;
    char pad10[8];
    unsigned char* items;
    void f(unsigned char value);
};
void X_298a00::f(unsigned char value) {
    --count;
    map[items[value]] = 0xff;
    if (count != value) {
        unsigned char* it = items;
        it[value] = it[count];
        map[items[value]] = value;
    }
    items[count] = 0xff;
}
