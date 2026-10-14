extern int g_cur_264d20;
extern int g_a_264d20;
extern int g_b_264d20;
extern char g_obj_264d20[];

int GetId();
int Conv(int);
void __cdecl Use(int);
void __cdecl Use2(void*);

class Q_264d20 {
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

void Q_264d20::Fn() {
    if (GetId() == g_cur_264d20) {
        unsigned s = m14;
        unsigned e = m18;
        int n;
        if (s <= e) {
            n = (int)(e - s) >> 3;
        } else {
            n = ((int)(e - m1c) >> 3) + ((int)(m20 - s) >> 3);
        }
        if ((unsigned)n > 0 || m8 != 0) {
            g_b_264d20 = Conv(g_a_264d20);
            Use2(g_obj_264d20);
        }
    } else {
        g_a_264d20 = Conv(g_b_264d20);
        Use(g_cur_264d20);
    }
}
