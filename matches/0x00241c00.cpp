// Same code shape as 0x00241880 (propagated; names are from that function)
struct Node {
    Node* a;
    Node* b;
    Node* c;
};
struct Tree_241c00 {
    Node* root;
};
void insert(Tree_241c00* param_1, Node* param_2) {
    Node* piVar1 = param_2->b;
    param_2->b = piVar1->a;
    if (piVar1->a != (Node*)(param_1 + 1)) {
        piVar1->a->c = param_2;
    }
    piVar1->c = param_2->c;
    Node* piVar2 = param_2->c;
    if (piVar2 == (Node*)(param_1 + 1)) {
        *reinterpret_cast<Node**>(param_1) = piVar1;
        piVar1->a = param_2;
        param_2->c = piVar1;
        return;
    }
    if (param_2 == piVar2->a) {
        piVar2->a = piVar1;
        piVar1->a = param_2;
        param_2->c = piVar1;
        return;
    }
    piVar2->b = piVar1;
    piVar1->a = param_2;
    param_2->c = piVar1;
}