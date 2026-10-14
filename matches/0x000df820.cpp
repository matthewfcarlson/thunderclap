extern int FUN_000f6610(int);

class C_df820 {
  public:
    void Add(int a, int b);
    char pad[0x200];
    struct E {
        int a;
        int b;
    } e[64];
};

void C_df820::Add(int a, int b) {
    int i = 0;
    while (i < 64) {
        if (e[i].a == 0)
            break;
        if (e[i + 1].a == 0) {
            i += 1;
            break;
        }
        if (e[i + 2].a == 0) {
            i += 2;
            break;
        }
        if (e[i + 3].a == 0) {
            i += 3;
            break;
        }
        i += 4;
    }
    if (i < 64) {
        e[i].a = FUN_000f6610(a);
        e[i].b = b;
    }
}
