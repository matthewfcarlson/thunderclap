// STATUS: equivalent (tools/equiv.py level 3: 509 inputs, branch coverage 228/230, incomplete)
// FUN_00218350 @ 0x00218350
#include "compat/ptr.h"
struct Table;
struct lua_State;

struct TObject {
    int tt;
    union {
        Table* h;
        void* gc;
        int b;
        float n;
    } value;
};

typedef TObject* StkId;
typedef unsigned int Instruction;

struct GCHeader {
    char pad0[4];
    unsigned char tt;
    unsigned char marked;
};

struct UpVal {
    char pad0[8];
    TObject* v;
};

struct Proto {
    char pad0[8];
    TObject* k;
    char padc[4];
    Proto** p;
    char pad14[0x44 - 0x14];
    unsigned char nups;
};

struct LClosure {
    char pad0[0xc];
    Proto* p;
    TObject g;
    UpVal* upvals[1];
};

struct CallInfo {
    StkId base;
    StkId top;
    const Instruction* savedpc;
    int tailcalls;
};

struct global_State {
    char pad0[0x48];
    unsigned int GCthreshold;
    unsigned int nblocks;
};

struct lua_State {
    char pad0[8];
    StkId top;
    StkId base;
    global_State* l_G;
    CallInfo* ci;
    char pad18[0x30 - 0x18];
    unsigned char hookmask;
    char pad31;
    unsigned char status;
    char pad33[5];
    int hookcount;
    char pad3c[4];
    TObject l_gt;
    TObject* openupval_pad;
};

#define LUA_MASKCALL 1
#define LUA_MASKLINE 4
#define LUA_MASKCOUNT 8
#define MAXSTACK 250

#define GET_OPCODE(i) ((i) & 0x3f)
#define GETARG_A(i) ((int)((i) >> 24))
#define GETARG_B(i) ((int)(((i) >> 15) & 0x1ff))
#define GETARG_C(i) ((int)(((i) >> 6) & 0x1ff))
#define GETARG_Bx(i) ((int)(((i) >> 6) & 0x3ffff))
#define GETARG_sBx(i) (GETARG_Bx(i) - 0x1ffff)

#define RA(i) (base + GETARG_A(i))
#define RB(i) (base + GETARG_B(i))
#define RKB(i) ((GETARG_B(i) < MAXSTACK) ? base + GETARG_B(i) : k + GETARG_B(i) - MAXSTACK)
#define RKC(i) ((GETARG_C(i) < MAXSTACK) ? base + GETARG_C(i) : k + GETARG_C(i) - MAXSTACK)
#define KBx(i) (k + GETARG_Bx(i))

#define ttisnil(o) ((o)->tt == 0)
#define ttisnumber(o) ((o)->tt == 3)
#define ttisstring(o) ((o)->tt == 4)
#define ttistable(o) ((o)->tt == 5)
#define ttisfunction(o) ((o)->tt == 6)
#define l_isfalse(o) (ttisnil(o) || ((o)->tt == 1 && (o)->value.b == 0))

#define tonumber(o, tmp)                                                                                     \
    ((o)->tt == 3 || (((o) = ((o)->tt == 4 && FUN_00215ff0((const char*)(o)->value.gc + 0x10, &num_))        \
                                 ? (((tmp)->value.n = num_), ((tmp)->tt = 3), (tmp))                         \
                                 : 0) != 0))

#define luaC_checkGC(L)                                                                                      \
    {                                                                                                        \
        if ((L)->l_G->nblocks >= (L)->l_G->GCthreshold)                                                      \
            FUN_00217440(L);                                                                                 \
    }

#define luaC_barrier(L, p, v)                                                                                \
    {                                                                                                        \
        if ((v)->tt >= 4 && (((GCHeader*)(v)->value.gc)->marked & 3) && (((GCHeader*)(p))->marked & 4))      \
            FUN_00217100(L, (GCHeader*)(p), (GCHeader*)(v)->value.gc);                                       \
    }

#define Arith_inline(op, expr, tm)                                                                           \
    {                                                                                                        \
        StkId rb_ = RKB(i);                                                                                  \
        StkId rc_ = RKC(i);                                                                                  \
        if (ttisnumber(rb_) && ttisnumber(rc_)) {                                                            \
            ra->tt = 3;                                                                                      \
            ra->value.n = expr;                                                                              \
        } else                                                                                               \
            base = FUN_00218170(rc_, rb_, pc, L, ra, tm);                                                    \
    }

void __cdecl FUN_00215520(lua_State* L, int event, int line);
// equiv-conv: FUN_002176c0 ebx edi
void FUN_002176c0(lua_State* L, const Instruction* pc);
void __cdecl FUN_00217830(lua_State* L, TObject* t, TObject* key, TObject* val);
void __cdecl FUN_00217980(lua_State* L, TObject* t, TObject* key, TObject* val);
void __cdecl FUN_00217100(lua_State* L, GCHeader* p, GCHeader* v);
void* __cdecl FUN_00219cc0(lua_State* L, int narray, int nhash);
void __cdecl FUN_00217440(lua_State* L);
// equiv-conv: FUN_00218170 eax ecx edx stack stack stack
StkId FUN_00218170(TObject* rc, TObject* rb, const Instruction* pc, lua_State* L, StkId ra, int op);
int __cdecl FUN_00215ff0(const char* s, float* result);
TObject* __cdecl FUN_002175b0(lua_State* L, const TObject* o, int event);
// equiv-conv: FUN_00217790 ecx eax
void FUN_00217790(lua_State* L, StkId res);
void __cdecl FUN_00214d40(lua_State* L, const TObject* p1, const TObject* p2);
void __cdecl FUN_00217f20(lua_State* L, int total, int last);
int __cdecl FUN_00217e20(lua_State* L, const TObject* t1, const TObject* t2);
int __cdecl FUN_00217cf0(lua_State* L, const TObject* l, const TObject* r);
// equiv-conv: FUN_00217d80 edi esi stack
int FUN_00217d80(const TObject* l, const TObject* r, lua_State* L);
StkId __cdecl FUN_00215790(lua_State* L, StkId func);
void __cdecl FUN_00215970(lua_State* L, int nresults, StkId firstResult);
void __cdecl FUN_00214a90(lua_State* L, const char* msg);
void __cdecl FUN_002159e0(lua_State* L, StkId func, int nresults);
void* __cdecl FUN_00219430(lua_State* L, const char* str, int l);
TObject* __cdecl FUN_00219e50(Table* t, void* key);
void* __cdecl FUN_00219f60(lua_State* L, void* h, int key);
void __cdecl FUN_00219660(lua_State* L, StkId level);
LClosure* __cdecl FUN_00219560(lua_State* L, int nelems, TObject* e);
UpVal* __cdecl FUN_00219610(lua_State* L, StkId level);

StkId __cdecl FUN_00218350(lua_State* L, int nexeccalls) {
    // A call installs a new frame and runs its hook; a return resumes a frame
    // without running the call hook again.
    bool enteringCall = true;
    for (;;) {
        LClosure* cl;
        StkId base;
        TObject* k;
        const Instruction* pc;
        bool switchFrame = false;

        if (enteringCall && (L->hookmask & LUA_MASKCALL))
            FUN_00215520(L, 0, -1);
        enteringCall = false;
        pc = L->ci->savedpc;
        cl = (LClosure*)(L->base - 1)->value.gc;
        base = L->base;
        k = cl->p->k;

        while (!switchFrame) {
            const Instruction i = *pc++;
            StkId ra;
            if ((L->hookmask & (LUA_MASKLINE | LUA_MASKCOUNT)) &&
                (--L->hookcount == 0 || L->hookmask & LUA_MASKLINE)) {
                FUN_002176c0(L, pc);
                if (L->status) {
                    L->ci->savedpc = pc - 1;
                    return 0;
                }
                base = L->base;
            }
            ra = RA(i);
            switch (GET_OPCODE(i)) {
            case 0: { /* OP_MOVE */
                *ra = *RB(i);
                break;
            }
            case 1: { /* OP_LOADK */
                *ra = *KBx(i);
                break;
            }
            case 2: { /* OP_LOADBOOL */
                ra->value.b = GETARG_B(i);
                ra->tt = 1;
                if (GETARG_C(i))
                    pc++;
                break;
            }
            case 3: { /* OP_LOADNIL */
                TObject* rb = RB(i);
                do {
                    (rb--)->tt = 0;
                } while (rb >= ra);
                break;
            }
            case 4: { /* OP_GETUPVAL */
                int b = GETARG_B(i);
                *ra = *cl->upvals[b]->v;
                break;
            }
            case 5: { /* OP_GETGLOBAL */
                L->ci->savedpc = pc;
                FUN_00217830(L, &cl->g, KBx(i), ra);
                base = L->base;
                break;
            }
            case 6: { /* OP_GETTABLE */
                L->ci->savedpc = pc;
                FUN_00217830(L, RB(i), RKC(i), ra);
                base = L->base;
                break;
            }
            case 7: { /* OP_SETGLOBAL */
                L->ci->savedpc = pc;
                FUN_00217980(L, &cl->g, KBx(i), ra);
                base = L->base;
                break;
            }
            case 8: { /* OP_SETUPVAL */
                UpVal* uv = cl->upvals[GETARG_B(i)];
                *uv->v = *ra;
                luaC_barrier(L, uv, ra);
                break;
            }
            case 9: { /* OP_SETTABLE */
                L->ci->savedpc = pc;
                FUN_00217980(L, ra, RKB(i), RKC(i));
                base = L->base;
                break;
            }
            case 10: { /* OP_NEWTABLE */
                int b = GETARG_B(i);
                ra->value.gc = FUN_00219cc0(L, (b & 7) << (b >> 3), GETARG_C(i));
                ra->tt = 5;
                L->ci->savedpc = pc;
                luaC_checkGC(L);
                base = L->base;
                break;
            }
            case 11: { /* OP_SELF */
                StkId rb = RB(i);
                ra[1] = *rb;
                L->ci->savedpc = pc;
                FUN_00217830(L, rb, RKC(i), ra);
                base = L->base;
                break;
            }
            case 12: { /* OP_ADD */
                Arith_inline(+, rb_->value.n + rc_->value.n, 5) break;
            }
            case 13: { /* OP_SUB */
                Arith_inline(-, rb_->value.n - rc_->value.n, 6) break;
            }
            case 14: { /* OP_MUL */
                Arith_inline(*, rb_->value.n * rc_->value.n, 7) break;
            }
            case 15: { /* OP_DIV */
                Arith_inline(/, rb_->value.n / rc_->value.n, 8) break;
            }
            case 16: { /* OP_POW */
                base = FUN_00218170(RKC(i), RKB(i), pc, L, ra, 9);
                break;
            }
            case 17: { /* OP_UNM */
                StkId rb = RB(i);
                TObject temp;
                float num_;
                if (tonumber(rb, &temp)) {
                    ra->tt = 3;
                    ra->value.n = -rb->value.n;
                } else {
                    TObject* tm;
                    temp.tt = 0;
                    L->ci->savedpc = pc;
                    tm = FUN_002175b0(L, RB(i), 10);
                    if (tm->tt == 0)
                        tm = FUN_002175b0(L, &temp, 10);
                    if (tm->tt == 6) {
                        *L->top = *tm;
                        L->top[1] = *RB(i);
                        L->top[2] = temp;
                        FUN_00217790(L, ra);
                    } else
                        FUN_00214d40(L, RB(i), &temp);
                    base = L->base;
                }
                break;
            }
            case 18: { /* OP_NOT */
                StkId rb = RB(i);
                ra->value.b = l_isfalse(rb) ? 1 : 0;
                ra->tt = 1;
                break;
            }
            case 19: { /* OP_CONCAT */
                int b = GETARG_B(i);
                int c = GETARG_C(i);
                L->ci->savedpc = pc;
                FUN_00217f20(L, c - b + 1, c);
                luaC_checkGC(L);
                base = L->base;
                *RA(i) = base[b];
                break;
            }
            case 20: { /* OP_JMP */
                pc += GETARG_sBx(i);
                break;
            }
            case 21: { /* OP_EQ */
                L->ci->savedpc = pc;
                if (((RKB(i)->tt == RKC(i)->tt) && FUN_00217e20(L, RKB(i), RKC(i))) != GETARG_A(i))
                    pc++;
                else
                    pc += GETARG_sBx(*pc) + 1;
                base = L->base;
                break;
            }
            case 22: { /* OP_LT */
                L->ci->savedpc = pc;
                if (FUN_00217cf0(L, RKB(i), RKC(i)) != GETARG_A(i))
                    pc++;
                else
                    pc += GETARG_sBx(*pc) + 1;
                base = L->base;
                break;
            }
            case 23: { /* OP_LE */
                L->ci->savedpc = pc;
                if (FUN_00217d80(RKB(i), RKC(i), L) != GETARG_A(i))
                    pc++;
                else
                    pc += GETARG_sBx(*pc) + 1;
                base = L->base;
                break;
            }
            case 24: { /* OP_TEST */
                StkId rb = RB(i);
                if (l_isfalse(rb) == GETARG_C(i))
                    pc++;
                else {
                    *ra = *rb;
                    pc += GETARG_sBx(*pc) + 1;
                }
                break;
            }
            case 25:   /* OP_CALL */
            case 26: { /* OP_TAILCALL */
                StkId firstResult;
                int b = GETARG_B(i);
                int nresults;
                if (b != 0)
                    L->top = ra + b;
                L->ci->savedpc = pc;
                firstResult = FUN_00215790(L, ra);
                if (firstResult) {
                    nresults = GETARG_C(i) - 1;
                    if (firstResult > L->top) {
                        (L->ci - 1)->savedpc = pc;
                        return 0;
                    }
                    FUN_00215970(L, nresults, firstResult);
                    if (nresults >= 0)
                        L->top = L->ci->top;
                    base = L->base;
                } else if (GET_OPCODE(i) == 25) {
                    nexeccalls++;
                    enteringCall = true;
                    switchFrame = true;
                } else {
                    // Re-read ci at each update: it may overlap the state itself.
                    int count;
                    base = (L->ci - 1)->base;
                    ra = RA(i);
                    if (L->openupval_pad)
                        FUN_00219660(L, base);
                    for (count = 0; ra + count < L->top; count++)
                        (base - 1)[count] = ra[count];
                    StkId newTop = base + count;
                    L->top = newTop;
                    (L->ci - 1)->top = newTop;
                    (L->ci - 1)->savedpc = L->ci->savedpc;
                    (L->ci - 1)->tailcalls++;
                    L->ci = L->ci - 1;
                    L->base = L->ci->base;
                    enteringCall = true;
                    switchFrame = true;
                }
                break;
            }
            case 27: { /* OP_RETURN */
                CallInfo* ci = L->ci - 1;
                int b = GETARG_B(i);
                int nresults;
                if (b != 0)
                    L->top = ra + b - 1;
                if (L->openupval_pad)
                    FUN_00219660(L, base);
                L->ci->savedpc = pc;
                if (--nexeccalls == 0)
                    return ra;
                nresults = GETARG_C(ci->savedpc[-1]) - 1;
                FUN_00215970(L, nresults, ra);
                if (nresults >= 0)
                    L->top = L->ci->top;
                switchFrame = true;
                break;
            }
            case 28: { /* OP_FORLOOP */
                float limit = ra[1].value.n;
                volatile float idx = ra[2].value.n + ra->value.n;
                if (ra[2].value.n > 0 ? idx <= limit : idx >= limit) {
                    pc += GETARG_sBx(i);
                    ra->value.n = idx;
                    ra->tt = 3;
                    ra[3].value.n = idx;
                    ra[3].tt = 3;
                }
                break;
            }
            case 29: { /* OP_FORPREP */
                TObject* init = ra;
                TObject* plimit = ra + 1;
                TObject* pstep = ra + 2;
                float num_;
                L->ci->savedpc = pc;
                if (!tonumber(init, ra))
                    FUN_00214a90(L, "`for' initial value must be a number");
                else if (!tonumber(plimit, ra + 1))
                    FUN_00214a90(L, "`for' limit must be a number");
                else if (!tonumber(pstep, ra + 2))
                    FUN_00214a90(L, "`for' step must be a number");
                ra->tt = 3;
                ra->value.n = ra->value.n - pstep->value.n;
                pc += GETARG_sBx(i);
                break;
            }
            case 30: { /* OP_TFORLOOP */
                StkId cb = ra + 3;
                cb[2] = ra[2];
                cb[1] = ra[1];
                cb[0] = ra[0];
                L->top = cb + 3;
                L->ci->savedpc = pc;
                FUN_002159e0(L, cb, GETARG_C(i));
                L->top = L->ci->top;
                base = L->base;
                cb = RA(i) + 3;
                if (cb->tt == 0)
                    pc++;
                else {
                    cb[-1] = *cb;
                    pc += GETARG_sBx(*pc) + 1;
                }
                break;
            }
            case 31: { /* OP_TFORPREP */
                if (ra->tt == 5) {
                    ra[1] = ra[0];
                    *ra = *FUN_00219e50(L->l_gt.value.h, FUN_00219430(L, "next", 4));
                }
                pc += GETARG_sBx(i);
                break;
            }
            case 32:
            case 33: { /* OP_SETLIST, OP_SETLISTO */
                int bc;
                hulk_intptr n;
                void* h;
                if (ra->tt != 5)
                    return 0;
                h = ra->value.h;
                bc = GETARG_Bx(i);
                if (GET_OPCODE(i) == 32)
                    n = (bc & 31) + 1;
                else {
                    n = L->top - ra - 1;
                    L->top = L->ci->top;
                }
                bc &= ~31;
                for (; n > 0; n--) {
                    TObject* o = (TObject*)FUN_00219f60(L, h, bc + n);
                    *o = ra[n];
                    luaC_barrier(L, h, &ra[n]);
                }
                break;
            }
            case 34: { /* OP_CLOSE */
                FUN_00219660(L, ra);
                break;
            }
            case 35: { /* OP_CLOSURE */
                Proto* p = cl->p->p[GETARG_Bx(i)];
                int nup = p->nups;
                LClosure* ncl = FUN_00219560(L, nup, &cl->g);
                int j;
                ncl->p = p;
                for (j = 0; j < nup; j++, pc++) {
                    if (GET_OPCODE(*pc) == 4)
                        ncl->upvals[j] = cl->upvals[GETARG_B(*pc)];
                    else
                        ncl->upvals[j] = FUN_00219610(L, base + GETARG_B(*pc));
                }
                ra->value.gc = ncl;
                ra->tt = 6;
                L->ci->savedpc = pc;
                luaC_checkGC(L);
                base = L->base;
                break;
            }
            }
        }
    }
}
