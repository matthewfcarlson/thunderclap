typedef unsigned char u8_92f70;
struct Thing_92f70 {
    char p[0x2c];
    u8_92f70 field;
};
struct Desc_92f70 {
    int x;
};
extern Thing_92f70* Cast(Thing_92f70*, int, const Desc_92f70*, const Desc_92f70*, int);
class C_92f70 {
  public:
    int values[1];
    char rest[0xbf4];
    void F(int c, int b, u8_92f70 d);
};
extern Desc_92f70 descA;
extern Desc_92f70 descB;
void C_92f70::F(int c, int b, u8_92f70 d) {
    if (b < 100 && c >= 0x266 && c <= 0x2c9) {
        Thing_92f70* t = Cast((Thing_92f70*)values[c], 0, &descA, &descB, 0);
        if (t) {
            *(int*)((char*)this + 0xbf8 + b * 4) = c;
            t->field = d;
        }
    }
}