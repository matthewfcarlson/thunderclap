// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 4/4)
// FUN_00219390 @ 0x00219390
extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);

struct TString_219390 {
    TString_219390 *next;
    unsigned char tt;
    unsigned char marked;
    unsigned char reserved;
    unsigned char pad;
    unsigned int hash;
    unsigned int len;
};
struct StringTable_219390 {
    TString_219390 **hash;
    unsigned int nuse;
    int size;
};
struct GlobalState_219390 {
    StringTable_219390 strt;
    char pad[8];
    unsigned char currentwhite;
};
struct lua_State_219390 {
    char pad[0x10];
    GlobalState_219390 *l_G;
};

void *__cdecl FUN_0021add0(lua_State_219390 *L, void *block, unsigned int oldSize, unsigned int newSize);
void __cdecl FUN_002192e0(lua_State_219390 *L, int newSize);

// Lua 5.0 newlstr: allocates a TString, copies the bytes and links it into the string table.
// equiv-conv: FUN_00219390 stack stack stack eax
TString_219390 *__cdecl FUN_00219390(lua_State_219390 *L, const char *str, unsigned int l, unsigned int h)
{
    TString_219390 *ts = (TString_219390 *)FUN_0021add0(L, 0, 0, l + 17);
    ts->len = l;
    ts->hash = h;
    ts->marked = L->l_G->currentwhite;
    ts->tt = 4;
    ts->reserved = 0;
    memcpy((char *)(ts + 1), str, l);
    ((char *)(ts + 1))[l] = 0;
    StringTable_219390 *tb = &L->l_G->strt;
    h &= tb->size - 1;
    ts->next = tb->hash[h];
    tb->hash[h] = ts;
    tb->nuse++;
    if (tb->nuse > (unsigned int)tb->size && tb->size <= 0x3ffffffe)
        FUN_002192e0(L, tb->size * 2);
    return ts;
}
