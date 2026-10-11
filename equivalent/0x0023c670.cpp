// STATUS: equivalent (tools/equiv.py level 3: 134 inputs, branch coverage 38/38)
// fight::Bank::vfunc_8 @ 0x0023c670
struct Node {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual Node *v8(void *ctx, float *weight);
    char pad04[0x10 - 4];
    int kind;
    char pad14[0x20 - 0x14];
    Node *next;
    Node *FUN_0023c300();
};

float __cdecl FUN_00238350(void *ctx);

class Bank {
public:
    char pad0[0x1c];
    Node *head;
    bool FUN_002333f0(void *ctx, int b);
    Node *FUN_0023c670(void *ctx, int b);
};

Node *Bank::FUN_0023c670(void *ctx, int b)
{
    if (!FUN_002333f0(ctx, b))
        return 0;

    float sum = 0.0f;
    for (Node *n = head; n; n = n->next) {
        if (n->kind == 2)
            continue;
        if (n->kind == 4) {
            Node *inner = n->FUN_0023c300();
            if (!inner || inner->kind == 2)
                continue;
        }
        float w = 0.0f;
        Node *hit = n->v8(ctx, &w);
        if (!hit)
            continue;
        if (!(w > 0.0f))
            return hit;
        sum = w + sum;
    }
    if (sum <= 0.0f)
        return 0;

    float target = FUN_00238350(ctx) * sum;
    float acc = 0.0f;
    for (Node *n = head; n; n = n->next) {
        if (n->kind == 2)
            continue;
        if (n->kind == 4) {
            Node *inner = n->FUN_0023c300();
            if (!inner || inner->kind == 2)
                continue;
        }
        float w = 0.0f;
        Node *hit = n->v8(ctx, &w);
        if (!hit)
            continue;
        if (!(w > 0.0f))
            continue;
        acc = w + acc;
        if (target <= acc)
            return hit;
    }
    return 0;
}
