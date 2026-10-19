// STATUS: equivalent (tools/equiv.py level 3: 112 inputs, branch coverage 23/23)
// FUN_00218170 @ 0x00218170
struct Str_218170 {
    char pad[0x10];
    char data[1];
};

struct TV {
    int tag;
    int val;
};

struct StrTV {
    int tag;
    Str_218170 *s;
};

struct Info14 {
    char pad[8];
    int line;
};

struct Info10 {
    char pad[0x98];
    int f98;
};

struct Ctx_218170 {
    char pad0[0xc];
    int f0c;
    Info10 *f10;
    Info14 *f14;
    char pad1[0x44 - 0x18];
    int f44;
};

struct Frame_218170 {
    TV a;
    TV b;
};

int FUN_00215ff0(const char *str, int *out);
TV *FUN_00219e50(int a, int b);
void FUN_00214a90(Ctx_218170 *ctx, const char *msg);
// equiv-conv: FUN_00217750 ecx stack eax edx
void FUN_00217750(Ctx_218170 *ctx, TV *fn, TV *lhs, TV *rhs);
// equiv-conv: FUN_00217790 ecx eax
void FUN_00217790(Ctx_218170 *ctx, TV *res);
// equiv-conv: FUN_00217af0 esi ebx edi stack stack
int FUN_00217af0(Ctx_218170 *ctx, TV *lhs, TV *rhs, TV *res, int op);
void FUN_00214d40(Ctx_218170 *ctx, TV *lhs, TV *rhs);

// equiv-conv: FUN_00218170 eax ecx edx stack stack stack
int FUN_00218170(TV *rhs, TV *lhs, int line, Ctx_218170 *ctx, TV *res, int op)
{
    Frame_218170 fr;
    TV *a;
    TV *b;
    ctx->f14->line = line;

    if (lhs->tag == 3) {
        b = lhs;
    } else {
        if (lhs->tag != 4)
            goto fallback;
        if (FUN_00215ff0(((StrTV *)lhs)->s->data, &fr.a.tag) == 0)
            goto fallback;
        fr.b.val = fr.a.tag;
        fr.b.tag = 3;
        b = &fr.b;
    }
    if (rhs->tag == 3) {
        a = rhs;
    } else {
        if (rhs->tag != 4)
            goto fallback;
        if (FUN_00215ff0(((StrTV *)rhs)->s->data, &fr.a.tag) == 0)
            goto fallback;
        fr.a.val = fr.a.tag;
        fr.a.tag = 3;
        a = &fr.a;
    }

    switch (op) {
    case 5: {
        float x = *(float *)&a->val + *(float *)&b->val;
        res->tag = 3;
        *(float *)&res->val = x;
        return ctx->f0c;
    }
    case 6: {
        float x = *(float *)&b->val - *(float *)&a->val;
        res->tag = 3;
        *(float *)&res->val = x;
        return ctx->f0c;
    }
    case 7: {
        float x = *(float *)&a->val * *(float *)&b->val;
        res->tag = 3;
        *(float *)&res->val = x;
        return ctx->f0c;
    }
    case 8: {
        float x = *(float *)&b->val / *(float *)&a->val;
        res->tag = 3;
        *(float *)&res->val = x;
        return ctx->f0c;
    }
    case 9: {
        TV *h = FUN_00219e50(ctx->f44, ctx->f10->f98);
        if (h->tag != 6)
            FUN_00214a90(ctx, "`__pow' (`^' operator) is not a function");
        FUN_00217750(ctx, h, b, a);
        FUN_00217790(ctx, res);
        return ctx->f0c;
    }
    default:
        return ctx->f0c;
    }

fallback:
    if (FUN_00217af0(ctx, lhs, rhs, res, op) == 0)
        FUN_00214d40(ctx, lhs, rhs);
    return ctx->f0c;
}
