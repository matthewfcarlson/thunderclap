struct Rec {
    int a, b, c, d, e;
};
struct Node {
    Rec r;
    Node* next;
};
struct Buffer {
    Rec* begin;
    Rec* cur;
    Rec* end;
};
extern "C" void* Alloc(unsigned int);
char FUN_001ad5c0(Buffer* b, Node* n) {
    unsigned int count = 0;
    Node* p = n;
    while (p) {
        p = p->next;
        ++count;
    }
    if (n && count > 0x100)
        return 0;
    Rec* old = b->begin;
    b->cur = old;
    if (b->end - old == 0) {
        Rec* q = (Rec*)Alloc(0x1400);
        b->begin = q;
        if (q) {
            b->cur = q;
            b->end = (Rec*)((char*)q + 0x1400);
        } else {
            b->cur = 0;
            b->end = 0;
        }
    }
    Node* current = n;
    while (current) {
        Rec* out = b->cur;
        if (out < b->end) {
            b->cur = out + 1;
            if (out) {
                Node* src = current;
                *out = src->r;
            }
        }
        current = current->next;
    }
    return 1;
}
