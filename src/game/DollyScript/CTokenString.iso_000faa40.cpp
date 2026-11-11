// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000f9870..0x000fb3b0 (kind game, layer game, confidence high), dominant class DollyScript::CTokenString
// (tree_prelude.h: not needed)


// 0x000faa40 FUN_000faa40 (636 B): equivalent/0x000faa40.cpp [isolated: code differs from its standalone build]
// sym: ?FUN_000faa40@Handler_faa40@fn_f138d869@@QAE_NPAVNode@2@@Z
#include "gen/owners.h"
#include "decls/data/game/DollyScript.h"
namespace fn_f138d869 {} using namespace fn_f138d869;
namespace fn_f138d869 {
// STATUS: equivalent (tools/equiv.py level 3: 20036 inputs, branch coverage 53/53)
// FUN_000faa40 @ 0x000faa40

extern char DAT_004a13e4[];
extern char DAT_004a1858[];
extern char DAT_004a1888[];
extern char DAT_004a1934[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);

class Node {
public:
    virtual ~Node();
    virtual __int64 Id();
    virtual Node *Clone();
    Node *next;
    char pad08[4];
    int flags;
};

struct Index_faa40 {
    Node *FUN_000f96b0(int lo, int hi);
};

struct StateStack_faa40 {
    int slot[4];
    int top;
};

struct Current_faa40 {
    Node *head;
};

class Handler_faa40 {
public:
    char pad0[8];
    Index_faa40 index;
    char pad9[0x808 - 0x8 - sizeof(Index_faa40)];
    StateStack_faa40 stack;
    Current_faa40 *current;
    int depth;

    void FUN_000fa870(Node *n);
    bool FUN_000faa40(Node *a1);
};

bool Handler_faa40::FUN_000faa40(Node *a1)
{
    bool result = true;
    Node *b = (Node *)FUN_00344e74(a1, 0, DAT_004a13e4, DAT_004a1934, 0);
    switch (stack.slot[stack.top]) {
    case 0:
        if (b == 0)
            return false;
        if (b->Id() == DAT_004e0a00) {
            ((owners::X_f9700 *)&stack)->FUN_000f9700(1);
        } else {
            if (!(b->Id() == DAT_004e0a18))
                return false;
            ((owners::X_f9700 *)&stack)->FUN_000f9700(2);
        }
        break;
    case 1: {
        __int64 id = b->Id();
        Node *n = ((Node *)((owners::Table_f9670 *)&index)->FUN_000f9670((int)id, (int)(id >> 32)));
        while (n != 0) {
            if (current != 0) {
                if (current->head == 0)
                    current->head = n->Clone();
                else
                {
                    Node * tmp1 = n->Clone();
                    ((owners::Node_f9b40 *)(current->head))->FUN_000f9b40((owners::Node_f9b40 *)(Node *)tmp1);
                }
            } else {
                Node *c = n->Clone();
                c->flags = b->flags;
                FUN_000fa870(c);
            }
            n = n->next;
        }
        if (stack.top > 0)
            stack.top--;
        break;
    }
    case 2: {
        __int64 id = b->Id();
        current = (Current_faa40 *)index.FUN_000f96b0((int)id, (int)(id >> 32));
        if (stack.top > 0)
            stack.top--;
        if (stack.top < 4) {
            stack.top++;
            stack.slot[stack.top] = 3;
        }
        break;
    }
    case 3:
        FUN_00344e74(a1, 0, DAT_004a13e4, DAT_004a1858, 0);
        if (stack.top > 0)
            stack.top--;
        if (stack.top < 4) {
            stack.top++;
            stack.slot[stack.top] = 4;
        }
        break;
    case 4:
        if (b != 0 && b->Id() == DAT_004e0a00) {
            ((owners::X_f9700 *)&stack)->FUN_000f9700(1);
            break;
        }
        if (FUN_00344e74(a1, 0, DAT_004a13e4, DAT_004a1888, 0) != 0) {
            if (depth > 0) {
                depth--;
            } else {
                ((owners::Stack_f9720 *)&stack)->FUN_000f9720();
                current = 0;
                break;
            }
        } else if (FUN_00344e74(a1, 0, DAT_004a13e4, DAT_004a1858, 0) != 0) {
            depth++;
        }
        if (current == 0)
            return true;
        if (current->head == 0) {
            current->head = a1;
            return result;
        }
        ((owners::Node_f9b40 *)(current->head))->FUN_000f9b40((owners::Node_f9b40 *)(Node *)a1);
        return result;
    default:
        return false;
    }
    delete a1;
    return result;
}
} // namespace fn_f138d869

