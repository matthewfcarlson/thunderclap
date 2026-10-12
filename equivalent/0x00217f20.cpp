// STATUS: equivalent (tools/equiv.py level 3: 116 inputs, branch coverage 31/32, incomplete)
// FUN_00217f20 @ 0x00217f20
extern "C" void* memcpy(void* dst, const void* src, unsigned int n);

struct TString {
    char pad00[0xc];
    unsigned int len;           // 0x0c
    char data[1];               // 0x10
};

struct TObject {
    int tt;
    void* value;
};

struct Mbuffer {
    char data[8];
};

struct Global {
    char pad00[0x3c];
    Mbuffer buff;               // 0x3c
};

struct lua_State {
    char pad00[8];
    TObject* top;               // 0x08
    TObject* base;              // 0x0c
    Global* G;                  // 0x10
    char pad14[4];
    TObject* stack_last;        // 0x18
    TObject* stack;             // 0x1c
};

int FUN_00217640(lua_State* L, TObject* o);
TObject* FUN_002175b0(lua_State* L, TObject* o, int event);
void FUN_00214d20(lua_State* L, TObject* p1, TObject* p2);
void FUN_00214a90(lua_State* L, const char* fmt, ...);
void FUN_00215460(lua_State* L, int n);
void FUN_002159e0(lua_State* L, TObject* func, int nresults);
char* FUN_0021a6b0(lua_State* L, Mbuffer* buff, unsigned int size);
TString* FUN_00219430(lua_State* L, const char* str, unsigned int len);

void FUN_00217f20(lua_State* L, int total, int last)
{
    int n;
    do {
        TObject* top = L->base + last + 1;
        n = 2;
        if ((top[-2].tt == 4 || FUN_00217640(L, top - 2)) &&
            (top[-1].tt == 4 || FUN_00217640(L, top - 1))) {
            TString* s1 = (TString*)top[-1].value;
            if (s1->len != 0) {
                unsigned int tl = ((TString*)top[-2].value)->len + s1->len;
                if (total > n) {
                    TObject* p = top - 3;
                    do {
                        if (p->tt != 4 && !FUN_00217640(L, p))
                            break;
                        tl += ((TString*)p->value)->len;
                        n++;
                        p--;
                    } while (n < total);
                }
                if (tl > 0xfffffffdu)
                    FUN_00214a90(L, "string size overflow");
                char* buffer = FUN_0021a6b0(L, &L->G->buff, tl);
                tl = 0;
                for (int i = n; i > 0; i--) {
                    TString* s = (TString*)top[-i].value;
                    unsigned int len = s->len;
                    memcpy(buffer + tl, s->data, len);
                    tl += len;
                }
                top[-n].value = FUN_00219430(L, buffer, tl);
                top[-n].tt = 4;
            }
        } else {
            TObject* a = top - 2;
            TObject* b = top - 1;
            TObject* tm = FUN_002175b0(L, a, 0xd);
            if (tm->tt == 0)
                tm = FUN_002175b0(L, b, 0xd);
            if (tm->tt != 6) {
                FUN_00214d20(L, a, b);
            } else {
                TObject* t = L->top;
                t->tt = 6;
                t->value = tm->value;
                t = L->top;
                t[1].tt = a->tt;
                t[1].value = a->value;
                t = L->top;
                t[2].tt = b->tt;
                t[2].value = b->value;
                int offset = (int)((char*)top - (char*)L->stack) - 0x10;
                if ((char*)L->stack_last - (char*)L->top <= 0x18)
                    FUN_00215460(L, 3);
                TObject* func = L->top;
                L->top = func + 3;
                FUN_002159e0(L, func, 1);
                TObject* res = L->top - 1;
                TObject* base = L->stack;
                L->top = res;
                TObject* dst = (TObject*)((char*)base + offset);
                dst->tt = res->tt;
                dst->value = res->value;
            }
        }
        total -= n - 1;
        last -= n - 1;
    } while (total > 1);
}
