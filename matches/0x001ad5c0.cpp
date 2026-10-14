struct Rec_1ad5c0 {
    int a, b, c, d, e;
};
struct Node {
    Rec_1ad5c0 r;
    Node* next;
};
struct Buffer_1ad5c0 {
    Rec_1ad5c0* begin;
    Rec_1ad5c0* cur;
    Rec_1ad5c0* end;
};
extern "C" void* Alloc(unsigned int);
char FUN_001ad5c0(Buffer_1ad5c0* b, Node* n) {
    unsigned int count = 0;
    Node* p = n;
    while (p) {
        p = p->next;
        ++count;
    }
    if (n && count > 0x100)
        return 0;
    Rec_1ad5c0* old = b->begin;
    b->cur = old;
    if (b->end - old == 0) {
        Rec_1ad5c0* q = (Rec_1ad5c0*)Alloc(0x1400);
        b->begin = q;
        if (q) {
            b->cur = q;
            b->end = (Rec_1ad5c0*)((char*)q + 0x1400);
        } else {
            b->cur = 0;
            b->end = 0;
        }
    }
    Node* current = n;
    while (current) {
        Rec_1ad5c0* out = b->cur;
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
