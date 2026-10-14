typedef unsigned char u8_299230;
struct Obj_299230 {
    char pad[0x0c];
    volatile u8_299230* table;
    void f(u8_299230 index);
    void g(int v);
};
void Obj_299230::f(u8_299230 index) {
    int value = table[index];
    if ((u8_299230)value != 0xff)
        g(value);
}
