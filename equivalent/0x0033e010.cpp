// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0033e010 @ 0x0033e010
struct lua_State;

const char *FUN_00339e60(lua_State *L, int narg, const char *def, unsigned int *len);
void FUN_00339d70(lua_State *L, int narg, int type);
void FUN_00212d80(lua_State *L, int idx);
int FUN_00339650(lua_State *L, int t);
void FUN_00339710(lua_State *L, int ref, int t);
void FUN_00213320(lua_State *L);
void FUN_00212e20(lua_State *L, int idx);
const char *FUN_0033df70(lua_State *L, void *ud, unsigned int *size);
int FUN_00213b20(lua_State *L, const char *(*reader)(lua_State *, void *, unsigned int *), void *ud, const char *chunkname);

struct LoadState_33e010 {
    int ref;
    int pending;
};

int FUN_0033e010(lua_State *L)
{
    LoadState_33e010 ls;
    const char *chunkname = FUN_00339e60(L, 2, "=(load)", 0);
    FUN_00339d70(L, 1, 6);
    FUN_00212d80(L, 1);
    ls.ref = FUN_00339650(L, -10000);
    ls.pending = -1;
    int status = FUN_00213b20(L, FUN_0033df70, &ls, chunkname);
    FUN_00339710(L, ls.ref, -10000);
    FUN_00339710(L, ls.pending, -10000);
    if (status == 0)
        return 1;
    FUN_00213320(L);
    FUN_00212e20(L, -2);
    return 2;
}
