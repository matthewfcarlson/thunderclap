class Node { public: int pad0[4]; int type; Node *next; void run(); };
extern void helper(Node *, int, const void *, const void *, int);
extern const int desc1;
extern const int desc2;
void Node::run() {
    if (type == 3) {
        helper(this, 0, &desc1, &desc2, 0);
        return;
    }
    Node *q = next;
    while (q != 0 && q->type != 3) q = q->next;
    helper(q, 0, &desc1, &desc2, 0);
}