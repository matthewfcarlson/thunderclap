struct Node {
    Node *a, *b, *parent;
    int color;
};
Node* FUN_002439c0(Node*, Node*);
void FUN_00243a00(Node*, Node*);
void FUN_002446d0(Node* n, Node* tree) {
    Node *s = (Node*)((char*)n + 4), *base = (Node*)((char*)tree + 0x58), *x;
    if (base->a != s && base->b != s)
        x = FUN_002439c0(n, base);
    else
        x = base;
    Node* l = x->a;
    Node* ed;
    if (l != s)
        ed = l;
    else
        ed = x->b;
    ed->parent = x->parent;
    Node* ec = x->parent;
    if (ec == s)
        *(Node**)n = ed;
    else if (x == ec->a)
        ec->a = ed;
    else
        ec->b = ed;
    int flag = x->color == 0;
    if (x != base) {
        x->parent = base->parent;
        x->a = base->a;
        x->b = base->b;
        x->color = base->color;
        ec = x->parent;
        if (ec != s) {
            if (ec->a == base)
                ec->a = x;
            else
                ec->b = x;
        } else
            *(Node**)n = x;
        ec = x->a;
        if (ec != s)
            ec->parent = x;
        ec = x->b;
        if (ec->parent != s)
            ec->parent = x;
    }
    if (flag)
        FUN_00243a00(n, ed);
}
