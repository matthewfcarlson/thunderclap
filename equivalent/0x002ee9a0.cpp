// STATUS: equivalent (tools/equiv.py level 3: 57 inputs, branch coverage 16/16)
// FUN_002ee9a0 @ 0x002ee9a0
struct Edge_2ee9a0 {
    int a;
    int b;
    int c;
    int d;
    int e;
};

struct Graph_2ee9a0 {
    char pad0[0x4c];
    Edge_2ee9a0 *begin;
    Edge_2ee9a0 *end;
    void FUN_002ee9a0(int a, int b);
};

void Graph_2ee9a0::FUN_002ee9a0(int a, int b)
{
    if (a == b)
        return;
    for (Edge_2ee9a0 *p = begin; p != end; p++) {
        if ((p->a == a || p->b == a) && (p->a == b || p->b == b)) {
            Edge_2ee9a0 *last = end - 1;
            end = last;
            if (p < last)
                *p = *last;
            return;
        }
    }
}
