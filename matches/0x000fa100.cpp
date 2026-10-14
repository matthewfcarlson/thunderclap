struct S_fa100 {
    char pad[0x10];
    unsigned char x;
    unsigned char y;
};
class C_fa100 {
    char p[4];

  public:
    int key;
    char q[0x0c];
    unsigned char out14;
    unsigned char out15;
    void f(S_fa100* src);
};
void C_fa100::f(S_fa100* src) {
    if (*(int*)src == key) {
        *(int*)((char*)this + 8) = *(int*)((char*)src + 4);
        *(int*)((char*)this + 0xc) = *(int*)((char*)src + 8);
        *(int*)((char*)this + 0x10) = *(int*)((char*)src + 0xc);
        out14 = src->y;
        out15 = src->x;
    }
}