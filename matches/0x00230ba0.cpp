typedef int(__cdecl* CompareFn_230ba0)(void*, void*);
struct Node_230ba0 {
    Node_230ba0* left;
    Node_230ba0* right;
};
class List_230ba0 {
  public:
    Node_230ba0* head;
    void* Find(CompareFn_230ba0 fn, void* key);
};
void* List_230ba0::Find(CompareFn_230ba0 fn, void* key) {
    Node_230ba0* p = head;
    Node_230ba0* end = (Node_230ba0*)((char*)this + sizeof(void*));
    while (p != end) {
        int r = fn(key, p);
        if (r < 0)
            p = p->left;
        else if (r > 0)
            p = p->right;
        else
            return p;
    }
    return 0;
}
