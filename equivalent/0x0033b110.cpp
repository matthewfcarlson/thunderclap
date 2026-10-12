// STATUS: equivalent (tools/equiv.py level 3: 166 inputs, branch coverage 35/36, incomplete)
// FUN_0033b110 @ 0x0033b110
struct lua_State;

extern "C" void __cdecl FUN_00213640(lua_State *L, int idx, int n);
extern "C" int __cdecl FUN_00212f00(lua_State *L, int idx);
extern "C" void __cdecl FUN_00212ed0(lua_State *L, int idx);
extern "C" void __cdecl FUN_002139a0(lua_State *L, int nargs, int nresults);
extern "C" int __cdecl FUN_00213160(lua_State *L, int idx);
extern "C" void __cdecl FUN_00212d80(lua_State *L, int idx);
extern "C" int __cdecl FUN_002130a0(lua_State *L, int a, int b);
extern "C" void __cdecl FUN_00213870(lua_State *L, int idx, int n);
extern "C" int FUN_00338e20(lua_State *L, const char *fmt, ...);

#define SORT_COMP(res, L, a, b) \
    do { \
        if (FUN_00212f00(L, 2)) { \
            FUN_00212ed0(L, 2); \
            FUN_00212ed0(L, (a) - 1); \
            FUN_00212ed0(L, (b) - 2); \
            FUN_002139a0(L, 2, 1); \
            res = FUN_00213160(L, -1); \
            FUN_00212d80(L, -2); \
        } else { \
            res = FUN_002130a0(L, a, b); \
        } \
    } while (0)

void __cdecl FUN_0033b110(lua_State *L, int l, int u)
{
    while (l < u) {
        int i, j, r;
        FUN_00213640(L, 1, l);
        FUN_00213640(L, 1, u);
        SORT_COMP(r, L, -1, -2);
        if (r) {
            FUN_00213870(L, 1, l);
            FUN_00213870(L, 1, u);
        } else {
            FUN_00212d80(L, -3);
        }
        if (u - l == 1)
            break;
        i = (l + u) / 2;
        FUN_00213640(L, 1, i);
        FUN_00213640(L, 1, l);
        SORT_COMP(r, L, -2, -1);
        if (r) {
            FUN_00213870(L, 1, i);
            FUN_00213870(L, 1, l);
        } else {
            FUN_00212d80(L, -2);
            FUN_00213640(L, 1, u);
            SORT_COMP(r, L, -1, -2);
            if (r) {
                FUN_00213870(L, 1, i);
                FUN_00213870(L, 1, u);
            } else {
                FUN_00212d80(L, -3);
            }
        }
        if (u - l == 2)
            break;
        FUN_00213640(L, 1, i);
        FUN_00212ed0(L, -1);
        FUN_00213640(L, 1, u - 1);
        FUN_00213870(L, 1, i);
        FUN_00213870(L, 1, u - 1);
        i = l;
        j = u - 1;
        for (;;) {
            for (;;) {
                FUN_00213640(L, 1, ++i);
                SORT_COMP(r, L, -1, -2);
                if (!r)
                    break;
                if (i > u)
                    FUN_00338e20(L, "invalid order function for sorting");
                FUN_00212d80(L, -2);
            }
            for (;;) {
                FUN_00213640(L, 1, --j);
                SORT_COMP(r, L, -3, -1);
                if (!r)
                    break;
                if (j < l)
                    FUN_00338e20(L, "invalid order function for sorting");
                FUN_00212d80(L, -2);
            }
            if (j < i) {
                FUN_00212d80(L, -4);
                break;
            }
            FUN_00213870(L, 1, i);
            FUN_00213870(L, 1, j);
        }
        FUN_00213640(L, 1, u - 1);
        FUN_00213640(L, 1, i);
        FUN_00213870(L, 1, u - 1);
        FUN_00213870(L, 1, i);
        if (i - l < u - i) {
            j = l;
            i = i - 1;
            l = i + 2;
        } else {
            j = i + 1;
            i = u;
            u = j - 2;
        }
        FUN_0033b110(L, j, i);
    }
}
