struct Node {
    char p[8];
    __int64 k;
};
struct Entry_1a57d0 {
    Node* n0;
    int p4, p8;
    Node* n1;
    int val;
    int p14;
};
class Obj_1a57d0 {
  public:
    char pad[0x30];
    Entry_1a57d0 e[20];
    int Find(__int64 k);
};
int Obj_1a57d0::Find(__int64 k) {
    int i;
    for (i = 0; i < 20; i++) {
        Node* n = e[i].n0;
        if (n && n->k == k)
            return e[i].val;
    }
    for (i = 0; i < 20; i++) {
        Node* n = e[i].n1;
        if (n && n->k == k)
            return e[i].val;
    }
    return 0;
}
