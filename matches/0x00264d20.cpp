extern int g_cur;
extern int g_a;
extern int g_b;
extern char g_obj[];

int GetId();
int Conv(int);
void __cdecl Use(int);
void __cdecl Use2(void*);

class Q {
  public:
    void Fn();
    char pad[8];
    int m8;
    char pad2[8];
    unsigned m14;
    unsigned m18;
    int m1c;
    int m20;
};

void Q::Fn() {
    if (GetId() == g_cur) {
        unsigned s = m14;
        unsigned e = m18;
        int n;
        if (s <= e) {
            n = (int)(e - s) >> 3;
        } else {
            n = ((int)(e - m1c) >> 3) + ((int)(m20 - s) >> 3);
        }
        if ((unsigned)n > 0 || m8 != 0) {
            g_b = Conv(g_a);
            Use2(g_obj);
        }
    } else {
        g_a = Conv(g_b);
        Use(g_cur);
    }
}
