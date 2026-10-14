struct Node {
    int a;
    int b;
};
int __cdecl FUN_002430d0(Node* p) {
    int r = p->b;
    if (r) {
        p->b = *(int*)r;
    } else {
        r = 0;
    }
    return r;
}
