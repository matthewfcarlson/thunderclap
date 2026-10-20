// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 34/36, incomplete)
// FUN_002324b0 @ 0x002324b0
#include "compat/ptr.h"
#include "decls/data/engine/fight.h"
#include "decls/data/game/global.h"

void *__cdecl FUN_00266da0(hulk_intptr n);
int __cdecl FUN_00238190(int n);

class Node {
public:
    virtual void AddRef();
    virtual void Release();
    virtual void v2();
    virtual void v3();
    virtual void Free();
    char pad4[4];
    Node *next;
    unsigned flags;
    char pad10[4];
    float time;
    float step;

    void FUN_00232600(int a, int b);
    void FUN_002326d0(Node *n);
};

class NodeList_2324b0 {
public:
    int f0;
    char pad4[0x1c];
    Node *head;
    Node *cur;

    void FUN_002321b0();
    bool FUN_002324b0(char flush);
};

bool NodeList_2324b0::FUN_002324b0(char flush)
{
    void *saved = FUN_00266da0(FUN_00238190(3));
    bool keep = false;
    Node *prev = 0;
    Node *n = head;
    while (n != 0) {
        if ((n->flags >> 2) & 1) {
            if ((n->flags >> 3) & 1) {
                n->Free();
                DAT_004e5ae8--;
            } else {
                float t = n->time;
                if (!(t < (*(float*)&DAT_003f32e0))) {
                    t -= n->step;
                    if (t < (*(float*)&DAT_003f32e0)) {
                        n->Free();
                        DAT_004e5ae8--;
                        n->FUN_00232600(8, 1);
                    } else {
                        n->time = t;
                    }
                }
            }
        }
        if ((n->flags >> 3) & 1) {
            if (cur == n) {
                if (prev != 0)
                    prev->AddRef();
                if (cur != 0)
                    cur->Release();
                cur = prev;
            }
            n = n->next;
            if (prev != 0) {
                prev->FUN_002326d0(n);
            } else {
                if (n != 0)
                    n->AddRef();
                if (head != 0)
                    head->Release();
                head = n;
            }
        } else {
            if ((n->flags & 3) == 0)
                keep = true;
            prev = n;
            n = n->next;
        }
    }
    if (!keep) {
        if (flush) {
            if (f0 != 0 || head != 0)
                FUN_002321b0();
        }
    }
    FUN_00266da0((hulk_intptr)saved);
    return keep;
}
