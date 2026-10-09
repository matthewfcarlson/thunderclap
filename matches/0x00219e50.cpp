typedef unsigned int uint;
typedef unsigned char byte;
struct A {
    char pad[7];
    byte shift;
    char pad2[8];
    void* buckets;
};
struct B {
    char pad[8];
    uint mask;
};
struct Node {
    int type;
    B* owner;
    int unused;
    int gap;
    Node* next;
};
extern int zero;
int* find(A* a, B* b) {
    uint x = 1u << a->shift;
    Node* p = (Node*)a->buckets + ((x - 1) & b->mask);
    while (p->type != 4 || p->owner != b) {
        p = p->next;
        if (!p)
            return &zero;
    }
    return (int*)p + 2;
}