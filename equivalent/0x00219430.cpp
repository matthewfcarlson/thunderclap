// STATUS: equivalent (tools/equiv.py level 3: 19954 inputs, branch coverage 14/14)
// FUN_00219430 @ 0x00219430
// FUN_00219430 @ 0x00219430: Lua 5.0 luaS_newlstr, interning a string by hash
struct TString_219430 {
    TString_219430 *next;
    unsigned char tt;
    unsigned char marked;
    char pad06[2];
    unsigned hash;
    unsigned len;
    char str[1];
};

struct stringtable {
    TString_219430 **hash;
    int nuse;
    int size;
};

struct global_State_219430 {
    stringtable strt;
    char pad0c[0x14 - 0x0c];
    unsigned currentwhite;
};

struct lua_State_219430 {
    char pad00[0x10];
    global_State_219430 *l_G;
};

// MSVC 7.1 expands memcmp inline (repe cmpsb); so does this.
static inline int memcmp_inline(const void *a, const void *b, unsigned n)
{
    const unsigned char *p = (const unsigned char *)a;
    const unsigned char *q = (const unsigned char *)b;
    for (; n != 0; n--, p++, q++)
        if (*p != *q)
            return *p - *q;
    return 0;
}

// equiv-conv: FUN_00219390 stack stack stack eax
TString_219430 *__cdecl FUN_00219390(lua_State_219430 *L, const char *str, unsigned len, unsigned h);

TString_219430 *__cdecl FUN_00219430(lua_State_219430 *L, const char *str, unsigned l)
{
    unsigned h = l;
    unsigned step = (l >> 5) + 1;
    for (unsigned l1 = l; l1 >= step; l1 -= step)
        h = h ^ ((h << 5) + (h >> 2) + (unsigned char)str[l1 - 1]);

    global_State_219430 *g = L->l_G;
    for (TString_219430 *ts = g->strt.hash[h & (g->strt.size - 1)]; ts != 0; ts = ts->next) {
        if (ts->len == l && memcmp_inline(str, ts->str, l) == 0) {
            global_State_219430 *g2 = L->l_G;
            if (ts->marked & (g2->currentwhite ^ 3))
                ts->marked ^= 3;
            return ts;
        }
    }
    return FUN_00219390(L, str, l, h);
}
