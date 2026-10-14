struct Item_1f4610 {
    int pad;
    int h;
};
struct Obj_1f4610 {
    char p[8];
    Item_1f4610* list[1];
    char q[0x88 - 0x0c];
    int count;
    Item_1f4610* a;
    char r[0xc0 - 0x90];
    Item_1f4610* b;
    Item_1f4610* c;
    char s[4];
    Item_1f4610* d;
    char t[0x330 - 0xd0];
    int guard;
    void Fn(char, char, char);
};
extern "C" void __cdecl Wait(int, int);
void Obj_1f4610::Fn(char x, char y, char z) {
    if (++guard == 1) {
        for (int i = 0; i < count; ++i) {
            Item_1f4610* v = list[i];
            if (v == a) {
                if (!x)
                    continue;
            } else if (v == b) {
                if (!y)
                    continue;
            } else if (v == c) {
                if (!z)
                    continue;
            } else if (v == d)
                continue;
            if (v->h)
                Wait(v->h, 500);
        }
    }
}
