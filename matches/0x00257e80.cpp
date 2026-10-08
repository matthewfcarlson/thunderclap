typedef unsigned int u32;
struct Node { Node *next; Node *prev; };
struct Head { Node *first; Node *last; };
void insert(Head *h, Node *n) {
    if (h->first == 0) {
        h->first = n;
        n->prev = 0;
        h->last = n;
        n->next = 0;
        return;
    }
    h->last->next = n;
    n->prev = h->last;
    h->last = n;
    n->next = 0;
}