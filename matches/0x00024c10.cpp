struct Node {
    char pad[0x128];
    int value;
};
struct Manager {
    Node* get(__int64);
};
__int64 __cdecl convert(int);
struct Obj {
    int pad;
    Manager* mgr;
    void set(int x, int y);
};
void Obj::set(int x, int y) {
    Manager* m = mgr;
    if (m) {
        __int64 a = convert(x);
        Node* n = m->get(a);
        n->value = y;
    }
}