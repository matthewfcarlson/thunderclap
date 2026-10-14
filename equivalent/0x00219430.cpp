// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 14/14)
// FUN_00219430 @ 0x00219430
// FUN_00219430 @ 0x00219430: Lua 5.0 luaS_newlstr, interning a string by hash
struct TString {
    TString *next;
    unsigned char tt;
    unsigned char marked;
    char pad06[2];
    unsigned hash;
    unsigned len;
    char str[1];
};

struct stringtable {
    TString **hash;
    int nuse;
    int size;
};

struct global_State {
    stringtable strt;
    char pad0c[0x14 - 0x0c];
    unsigned currentwhite;
};

struct lua_State {
    char pad00[0x10];
    global_State *l_G;
};

extern "C" int __cdecl memcmp(const void *, const void *, unsigned int);

// equiv-conv: FUN_00219390 stack stack stack eax
TString *__cdecl FUN_00219390(lua_State *L, const char *str, unsigned len, unsigned h);

TString *__cdecl FUN_00219430(lua_State *L, const char *str, unsigned l)
{
    unsigned h = l;
    unsigned step = (l >> 5) + 1;
    for (unsigned l1 = l; l1 >= step; l1 -= step)
        h = h ^ ((h << 5) + (h >> 2) + (unsigned char)str[l1 - 1]);

    global_State *g = L->l_G;
    for (TString *ts = g->strt.hash[h & (g->strt.size - 1)]; ts != 0; ts = ts->next) {
        if (ts->len == l && memcmp(str, ts->str, l) == 0) {
            global_State *g2 = L->l_G;
            if (ts->marked & (g2->currentwhite ^ 3))
                ts->marked ^= 3;
            return ts;
        }
    }
    return FUN_00219390(L, str, l, h);
}
