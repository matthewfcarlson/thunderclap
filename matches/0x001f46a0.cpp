class Obj {
  public:
    char pad0[8];
    struct Entry {
        int pad;
        int value;
    }* items[32];
    int count;
    char pad1[0x330 - 0x8 - 32 * 4 - 4];
    int state;
    void Fn();
};
extern void __cdecl FUN_00247970(int, int);
void Obj::Fn() {
    int x = state;
    if (x == 1) {
        state = 0;
        for (int i = 0; i < count; ++i) {
            int v = items[i]->value;
            if (v)
                FUN_00247970(v, 500);
        }
    } else if (x > 1)
        state = x - 1;
}
