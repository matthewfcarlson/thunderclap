// STATUS: equivalent (tools/equiv.py level 3: 57 inputs, branch coverage 16/16)
// FUN_002ee9a0 @ 0x002ee9a0
struct Edge {
    int a;
    int b;
    int c;
    int d;
    int e;
};

struct Graph {
    char pad0[0x4c];
    Edge *begin;
    Edge *end;
    void FUN_002ee9a0(int a, int b);
};

void Graph::FUN_002ee9a0(int a, int b)
{
    if (a == b)
        return;
    for (Edge *p = begin; p != end; p++) {
        if ((p->a == a || p->b == a) && (p->a == b || p->b == b)) {
            Edge *last = end - 1;
            end = last;
            if (p < last)
                *p = *last;
            return;
        }
    }
}
