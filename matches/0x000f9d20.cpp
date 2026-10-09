class Node { public: virtual void Release(int); Node* next; };
struct Entry { int a; int b; Node* head; int pad; };
void __fastcall ClearEntries(Entry* p) {
    int i = 128;
    do {
        if (p->a | p->b) {
            Node* n = p->head;
            while (n) {
                Node* nx = n->next;
                n->Release(1);
                n = nx;
            }
            p->a = 0;
            p->b = 0;
        }
        p++;
    } while (--i != 0);
}
