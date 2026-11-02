// Same code shape as 0x00241880 (propagated; names are from that function)
struct Node {
    Node* a;
    Node* b;
    Node* c;
};
struct Tree_256850 {
    Node* root;
};
extern "C" void FUN_00256850(void * param_1, void * param_2) {
    Node* piVar1 = ((Node *)param_2)->b;
    ((Node *)param_2)->b = piVar1->a;
    if (piVar1->a != (Node*)(((Tree_256850 *)param_1) + 1)) {
        piVar1->a->c = ((Node *)param_2);
    }
    piVar1->c = ((Node *)param_2)->c;
    Node* piVar2 = ((Node *)param_2)->c;
    if (piVar2 == (Node*)(((Tree_256850 *)param_1) + 1)) {
        *reinterpret_cast<Node**>(((Tree_256850 *)param_1)) = piVar1;
        piVar1->a = ((Node *)param_2);
        ((Node *)param_2)->c = piVar1;
        return;
    }
    if (((Node *)param_2) == piVar2->a) {
        piVar2->a = piVar1;
        piVar1->a = ((Node *)param_2);
        ((Node *)param_2)->c = piVar1;
        return;
    }
    piVar2->b = piVar1;
    piVar1->a = ((Node *)param_2);
    ((Node *)param_2)->c = piVar1;
}