// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_0024ac40 @ 0x0024ac40
// FUN_0024ac40: find the first open (type 0/1/2) node of a list and fill it in, else append a new one
struct Node {
    Node *next;
    char pad04[8];
    int type;
    char flag;
    char pad11[3];
    int value;
    int srcLo;
    int srcHi;
    int f20;
    float f24;
    int f28;
};

struct Owner {
    char pad00[0x10];
    Node *head;
};

struct Pair {
    int lo;
    int hi;
};

Node *__cdecl FUN_0024a9c0(void *a, Owner *b);
void __cdecl FUN_00247ae0(void *a, Node *n, int b, int c, Pair *d);

void __cdecl FUN_0024ac40(void *ctx, Owner *owner, int flag, int value, Pair *src)
{
    for (Node *n = owner->head; n != 0; n = n->next) {
        if (n->type == 0 || n->type == 1 || n->type == 2) {
            n->flag = (char)flag;
            n->type = 3;
            n->value = value;
            if (src != 0) {
                n->srcLo = src->lo;
                n->srcHi = src->hi;
            } else {
                n->srcLo = 0;
                n->srcHi = 0;
            }
            n->f28 = 0;
            n->f20 = 0;
            if (n->srcHi == 0)
                n->f24 = 1.0f;
            else
                *(int *)&n->f24 = 0;
            return;
        }
    }
    Node *fresh = FUN_0024a9c0(ctx, owner);
    if (fresh != 0)
        FUN_00247ae0(ctx, fresh, flag, value, src);
}
