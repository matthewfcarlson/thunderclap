// STATUS: equivalent (tools/equiv.py level 3: 106 inputs, branch coverage 33/38, incomplete)
// FUN_001d6770 @ 0x001d6770
struct GraphEntry {
    int pad0;
    int pad4;
    int type;
    int value;
};

struct GraphNode {
    char pad00[0x24];
    int count;
    GraphEntry *entries;
};

struct Graph_1d6770 {
    GraphNode *FUN_001d56f0(int id);
    int FUN_001d5710();
};

struct Listener_1d6770 {
    void FUN_002fc670(int v);
};

class StateWalker {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void vfunc_16(int state, int flag);
    char pad04[0x40 - 4];
    int current;
    char pad44[0xa0 - 0x44];
    Listener_1d6770 *listener;
    char pada4[0xec - 0xa4];
    Graph_1d6770 *graph;
    void FUN_001d6770();
};

void StateWalker::FUN_001d6770()
{
    int best = -1;
    int cur = current;
    int ring[8];
    int ringIdx = 0;
    int iterations = 0;
    int k;

    for (k = 0; k < 8; k++)
        ring[k] = -1;

    for (;;) {
        ring[ringIdx] = cur;
        ringIdx = (ringIdx + 1) % 8;

        GraphNode *node = graph->FUN_001d56f0(cur);
        int count = node->count;
        bool found = false;
        bool hit = false;
        if (count > 0) {
            int start = current;
            GraphEntry *e = node->entries;
            for (int i = 0; i < count; i++, e++) {
                if (cur == start && e->type == 10) {
                    best = e->value;
                    hit = true;
                    break;
                }
                if (e->type == 13) {
                    cur = e->value;
                    found = true;
                    if (cur == start) {
                        best = graph->FUN_001d5710() - 1;
                        hit = true;
                        break;
                    }
                }
            }
        }

        if (!hit && !found) {
            if (best < 0) {
                if (cur != current)
                    best = cur;
                if (best < 0)
                    best = graph->FUN_001d5710() - 1;
            }
            break;
        }

        if (best < 0) {
            for (k = 0; k < 8; k++) {
                if (cur == ring[k]) {
                    best = graph->FUN_001d5710() - 1;
                    break;
                }
            }
        }
        iterations++;
        if (best >= 0)
            break;
        if (iterations >= 0x20)
            best = graph->FUN_001d5710() - 1;
        if (best >= 0)
            break;
    }

    if (current != best) {
        if (listener)
            listener->FUN_002fc670(2);
        vfunc_16(best, 1);
    }
}
