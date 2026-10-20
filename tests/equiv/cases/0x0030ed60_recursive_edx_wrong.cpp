// FUN_0030ed60 @ 0x0030ed60
// native13: the original keeps the node in edx across its call of 0x0030ecb0 (which never writes edx: whole-
// program register allocation); the byte-matched source read it back as the high half of a 64-bit return, which
// a native definition doesn't preserve. Here the node is an ordinary local (MSVC 7.1 can't emit the original's
// register use, so this is an equivalent, not a match).
class Node {
  public:
    char pad0[12];
    int count;
    Node** children;
    char pad1[0xa8];
    int state;
    void Step();
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
            p->state = 3;
            if (n > 0) {
                int j = 0;
                do {
                    p->children[j]->Step();
                    ++j;
                } while (j < p->count);
            }
        }
    }
}
