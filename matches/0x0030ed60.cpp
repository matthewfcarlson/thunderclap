class Node {
  public:
    char pad0[12];
    int count;
    Node** children;
    char pad1[0xa8];
    int state;
    unsigned __int64 Step();
};
class Owner {
  public:
    char pad[12];
    int count;
    Node** children;
    void Traverse();
};
void Owner::Traverse() {
    for (int i = 0; i < count; ++i) {
        Node* p = children[i];
        if (p->state == 0) {
            int n = p->count;
            int j = 0;
            p->state = 2;
            if (n > 0) {
                do {
                    unsigned __int64 r = p->children[j]->Step();
                    p = (Node*)(unsigned int)(r >> 32);
                    ++j;
                } while (j < p->count);
            }
        }
    }
}