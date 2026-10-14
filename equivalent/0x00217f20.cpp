// STATUS: equivalent (tools/equiv.py level 3: 116 inputs, branch coverage 31/32, incomplete)
// FUN_00217f20 @ 0x00217f20
extern "C" void* memcpy(void* dst, const void* src, unsigned int n);

struct TString_217f20 {
    char pad00[0xc];
    unsigned int len;           // 0x0c
    char data[1];               // 0x10
};

struct TObject_217f20 {
    int tt;
    void* value;
};

struct Mbuffer_217f20 {
    char data[8];
};

struct Global_217f20 {
    char pad00[0x3c];
    Mbuffer_217f20 buff;               // 0x3c
};

struct lua_State_217f20 {
    char pad00[8];
    TObject_217f20* top;               // 0x08
    TObject_217f20* base;              // 0x0c
    Global_217f20* G;                  // 0x10
    char pad14[4];
    TObject_217f20* stack_last;        // 0x18
    TObject_217f20* stack;             // 0x1c
};

int FUN_00217640(lua_State_217f20* L, TObject_217f20* o);
TObject_217f20* FUN_002175b0(lua_State_217f20* L, TObject_217f20* o, int event);
void FUN_00214d20(lua_State_217f20* L, TObject_217f20* p1, TObject_217f20* p2);
void FUN_00214a90(lua_State_217f20* L, const char* fmt, ...);
void FUN_00215460(lua_State_217f20* L, int n);
void FUN_002159e0(lua_State_217f20* L, TObject_217f20* func, int nresults);
char* FUN_0021a6b0(lua_State_217f20* L, Mbuffer_217f20* buff, unsigned int size);
TString_217f20* FUN_00219430(lua_State_217f20* L, const char* str, unsigned int len);

void FUN_00217f20(lua_State_217f20* L, int total, int last)
{
    int n;
    do {
        TObject_217f20* top = L->base + last + 1;
        n = 2;
        if ((top[-2].tt == 4 || FUN_00217640(L, top - 2)) &&
            (top[-1].tt == 4 || FUN_00217640(L, top - 1))) {
            TString_217f20* s1 = (TString_217f20*)top[-1].value;
            if (s1->len != 0) {
                unsigned int tl = ((TString_217f20*)top[-2].value)->len + s1->len;
                if (total > n) {
                    TObject_217f20* p = top - 3;
                    do {
                        if (p->tt != 4 && !FUN_00217640(L, p))
                            break;
                        tl += ((TString_217f20*)p->value)->len;
                        n++;
                        p--;
                    } while (n < total);
                }
                if (tl > 0xfffffffdu)
                    FUN_00214a90(L, "string size overflow");
                char* buffer = FUN_0021a6b0(L, &L->G->buff, tl);
                tl = 0;
                for (int i = n; i > 0; i--) {
                    TString_217f20* s = (TString_217f20*)top[-i].value;
                    unsigned int len = s->len;
                    memcpy(buffer + tl, s->data, len);
                    tl += len;
                }
                top[-n].value = FUN_00219430(L, buffer, tl);
                top[-n].tt = 4;
            }
        } else {
            TObject_217f20* a = top - 2;
            TObject_217f20* b = top - 1;
            TObject_217f20* tm = FUN_002175b0(L, a, 0xd);
            if (tm->tt == 0)
                tm = FUN_002175b0(L, b, 0xd);
            if (tm->tt != 6) {
                FUN_00214d20(L, a, b);
            } else {
                TObject_217f20* t = L->top;
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
                TObject_217f20* func = L->top;
                L->top = func + 3;
                FUN_002159e0(L, func, 1);
                TObject_217f20* res = L->top - 1;
                TObject_217f20* base = L->stack;
                L->top = res;
                TObject_217f20* dst = (TObject_217f20*)((char*)base + offset);
                dst->tt = res->tt;
                dst->value = res->value;
            }
        }
        total -= n - 1;
        last -= n - 1;
    } while (total > 1);
}
