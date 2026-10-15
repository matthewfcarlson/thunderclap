struct Node {
    Node* left;
    Node* parent;
    Node* right;
};
extern "C" Node* __cdecl FUN_0025e9b0(Node* x, Node* head) {
    Node* nil = (Node*)((char*)x + 4);
    Node* y = head->parent;
    if (y != nil) {
        while (y->left != nil)
            y = y->left;
        return y;
    }
    y = head->right;
    if (y != nil) {
        do {
            if (head != y->parent)
                break;
            head = y;
            y = y->right;
        } while (y != nil);
    }
    return y;
}