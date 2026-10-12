// STATUS: equivalent (tools/equiv.py level 3: 108 inputs, branch coverage 34/34)
// FUN_001e5bc0 @ 0x001e5bc0
struct Item {
    char pad00[0x16];
    short s16;
    char pad18[0x22 - 0x18];
    short s22;
    char pad24[4];
    void FUN_001dbba0();
};

struct Node {
    int w0;
    int w4;
    int w8;
    unsigned int wc;
    unsigned char flags;
    unsigned char flags2;
    short item;
};

class Pool {
public:
    char pad000[0x608];
    Item items[0x800];
    Node nodes[0x800];
    int pad1e608;
    int a;
    int b;
    int c;
    char pad1e618[0x1ec58 - 0x1e618];
    int counter;
    void FUN_001e5980(int node);
    void FUN_001e5bc0(int idx);
};

void Pool::FUN_001e5bc0(int idx)
{
    if (idx < 0 || idx >= 0x800)
        return;
    Item* it = &items[idx];
    if (it->s16 == 0)
        return;
    int ni = it->s22;
    Node* n = &nodes[ni];
    if (n->flags & 1) {
        FUN_001e5980(ni);
        if (it->s16 == 0)
            return;
    }
    if (n->flags2 & 0x20)
        counter--;
    it->FUN_001dbba0();
    int last = c - 1;
    int e = ni;
    if (ni != last) {
        if (ni < a) {
            if (ni != a - 1) {
                nodes[ni] = nodes[a - 1];
                items[nodes[ni].item].s22 = (short)ni;
                e = a - 1;
            }
            if (b <= c - 1) {
                nodes[e] = nodes[b];
                items[nodes[e].item].s22 = (short)e;
                e = b;
            }
            if (e < c - 1) {
                nodes[e] = nodes[c - 1];
                items[nodes[e].item].s22 = (short)e;
            }
            a = a - 1;
            b = b - 1;
        } else if (ni <= b && b <= last) {
            if (ni != b) {
                nodes[ni] = nodes[b];
                items[nodes[ni].item].s22 = (short)ni;
                e = b;
            }
            if (e < c - 1) {
                nodes[e] = nodes[c - 1];
                items[nodes[e].item].s22 = (short)e;
            }
            b = b - 1;
        } else {
            nodes[ni] = nodes[c - 1];
            items[nodes[ni].item].s22 = (short)ni;
        }
    }
    Node* t = &nodes[c - 1];
    t->w0 = 0;
    t->w4 = 0;
    t->w8 = 0;
    t->wc = 0x7f7fffff;
    t->flags = 0;
    t->flags2 = 0;
    t->item = -1;
    c = c - 1;
    if (a > c)
        a = c;
    if (b > c)
        b = c;
}
