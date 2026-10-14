// STATUS: equivalent (tools/equiv.py level 3: 58 inputs, branch coverage 16/16)
// FUN_00300080 @ 0x00300080
struct Edge_300080 {
    int a;
    int b;
    int c;
    int d;
    int e;
};

struct Graph_300080 {
    char pad0[0x30];
    Edge_300080 *begin;
    Edge_300080 *end;
    void FUN_00300080(int a, int b);
};

void Graph_300080::FUN_00300080(int a, int b)
{
    if (a == b)
        return;
    for (Edge_300080 *p = begin; p != end; p++) {
        if ((p->a == a || p->b == a) && (p->a == b || p->b == b)) {
            Edge_300080 *last = end - 1;
            end = last;
            if (p < last)
                *p = *last;
            return;
        }
    }
}
