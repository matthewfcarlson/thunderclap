// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 13/13)
// FUN_00213ba0 @ 0x00213ba0
struct Global_213ba0 {
    char pad0[0x48];
    unsigned threshold;
    unsigned total;
};

struct lua_State_213ba0 {
    char pad0[0x10];
    Global_213ba0 *g;
};

void __cdecl FUN_00217490(lua_State_213ba0 *L);
void __cdecl FUN_00217440(lua_State_213ba0 *L);

int __cdecl FUN_00213ba0(lua_State_213ba0 *L, int what, int data)
{
    Global_213ba0 *g = L->g;
    switch (what) {
    case 0:
        g->threshold = 0x7fffffff;
        return 0;
    case 1:
        g->threshold = g->total;
        return 0;
    case 2:
        FUN_00217490(L);
        return 0;
    case 3:
        return g->total >> 10;
    case 4:
        if (data > 0) {
            int n = data;
            do {
                if (g->total < g->threshold)
                    g->threshold = g->total;
                FUN_00217440(L);
                n--;
            } while (n != 0);
        }
        return 0;
    }
    return -1;
}
