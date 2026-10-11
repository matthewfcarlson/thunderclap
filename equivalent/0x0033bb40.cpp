// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 10/10)
// FUN_0033bb40 @ 0x0033bb40
struct lua_State;

extern "C" int rand(void);
extern "C" double floor(double);

int FUN_00212d70(lua_State *L);
int FUN_00339f70(lua_State *L, int arg);
int FUN_00339c30(lua_State *L, int arg, const char *msg);
void FUN_00213340(lua_State *L, float n);
int FUN_00338e20(lua_State *L, const char *msg);

// math.random
int FUN_0033bb40(lua_State *L)
{
    float r = (float)(rand() % 0x7fff) * 3.0518509e-05f;
    switch (FUN_00212d70(L)) {
    case 0:
        FUN_00213340(L, r);
        return 1;
    case 1: {
        int u = FUN_00339f70(L, 1);
        if (u < 1)
            FUN_00339c30(L, 1, "interval is empty");
        FUN_00213340(L, (float)((int)floor(u * r) + 1));
        return 1;
    }
    case 2: {
        int lo = FUN_00339f70(L, 1);
        int hi = FUN_00339f70(L, 2);
        if (lo > hi)
            FUN_00339c30(L, 2, "interval is empty");
        FUN_00213340(L, (float)((int)floor((hi - lo + 1) * r) + lo));
        return 1;
    }
    default:
        return FUN_00338e20(L, "wrong number of arguments");
    }
}
