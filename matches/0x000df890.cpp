int Dup(int a);
struct Slot_df890 {
    int a;
    int b;
};
struct S_df890 {
    char pad[0x400];
    Slot_df890 s[64];
    void Add(int a, int b);
};
void S_df890::Add(int a, int b) {
    int i = 0;
    int* p = (int*)((char*)this + 0x408);
    do {
        if (p[-2] == 0)
            break;
        if (p[0] == 0) {
            i += 1;
            break;
        }
        if (p[2] == 0) {
            i += 2;
            break;
        }
        if (p[4] == 0) {
            i += 3;
            break;
        }
        i += 4;
        p += 8;
    } while (i < 64);
    if (i < 64) {
        s[i].a = Dup(a);
        s[i].b = b;
    }
}
