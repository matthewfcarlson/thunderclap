#include "decls/data/engine/audio.h"
#include "decls/data/engine/content.h"
// data: g_cur_264d20 = DAT_00527c4c, g_obj_264d20 = DAT_00527c28

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
    if (GetId() == (*(int*)&DAT_00527c4c)) {
        unsigned s = m14;
        unsigned e = m18;
        int n;
        if (s <= e) {
            n = (int)(e - s) >> 3;
        } else {
            n = ((int)(e - m1c) >> 3) + ((int)(m20 - s) >> 3);
        }
        if ((unsigned)n > 0 || m8 != 0) {
            (*(int*)&DAT_00527c54) = Conv((*(int*)&DAT_00527c50));
            Use2(((char*)((char*)&DAT_0051de40 + 40424)));
        }
    } else {
        (*(int*)&DAT_00527c50) = Conv((*(int*)&DAT_00527c54));
        Use((*(int*)&DAT_00527c4c));
    }
}
