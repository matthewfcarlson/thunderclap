struct Node {
    Node* left;
    Node* right;
    Node* parent;
};
typedef void(__cdecl* Callback)(Node*, int);
class Container {
  public:
    Node* root;
    int pad;
    Node* head;
    Node* tail;
    char flag[4];
    int value;
    void Clear(Callback cb, int arg);
};
void Container::Clear(Callback cb, int arg) {
    Node* sent = (Node*)((char*)this + 4);
    Node* n = root;
    if (n != sent)
        do {
            for (;;) {
                Node* p;
                while (n->left != sent)
                    n = n->left;
                p = n->right;
                if (p == sent)
                    break;
                n = p;
            }
            Node* ret = n;
            n = n->parent;
            if (n->left != sent)
                n->left = sent;
            else
                n->right = sent;
            cb(ret, arg);
        } while (n != sent);
    root = sent;
    head = sent;
    tail = sent;
    sent->left = sent;
    flag[0] = 0;
    value = 0;
}
