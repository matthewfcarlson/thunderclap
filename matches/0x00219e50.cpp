typedef unsigned int uint;
typedef unsigned char byte;
struct A_219e50 {
    char pad[7];
    byte shift;
    char pad2[8];
    void* buckets;
};
struct B_219e50 {
    char pad[8];
    uint mask;
};
struct Node {
    int type;
    B_219e50* owner;
    int unused;
    int gap;
    Node* next;
};
extern int zero_219e50;
int* find(A_219e50* a, B_219e50* b) {
    uint x = 1u << a->shift;
    Node* p = (Node*)a->buckets + ((x - 1) & b->mask);
    while (p->type != 4 || p->owner != b) {
        p = p->next;
        if (!p)
            return &zero_219e50;
    }
    return (int*)p + 2;
}