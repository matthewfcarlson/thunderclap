// STATUS: equivalent (tools/equiv.py level 3: 163 inputs, branch coverage 53/53)
// FUN_000faa40 @ 0x000faa40
extern char DAT_004a13e4[];
extern char DAT_004a1858[];
extern char DAT_004a1888[];
extern char DAT_004a1934[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
extern __int64 DAT_004e0a00;
extern __int64 DAT_004e0a18;

class Node {
public:
    virtual ~Node();
    virtual __int64 Id();
    virtual Node *Clone();
    Node *next;
    char pad08[4];
    int flags;
    void FUN_000f9b40(Node *child);
};

struct Index {
    Node *FUN_000f9670(int lo, int hi);
    Node *FUN_000f96b0(int lo, int hi);
};

struct StateStack {
    int slot[4];
    int top;
    void FUN_000f9700(int state);
    void FUN_000f9720();
};

struct Current {
    Node *head;
};

class Handler {
public:
    char pad0[8];
    Index index;
    char pad9[0x808 - 0x8 - sizeof(Index)];
    StateStack stack;
    Current *current;
    int depth;

    void FUN_000fa870(Node *n);
    bool FUN_000faa40(Node *a1);
};

bool Handler::FUN_000faa40(Node *a1)
{
    bool result = true;
    Node *b = (Node *)FUN_00344e74(a1, 0, DAT_004a13e4, DAT_004a1934, 0);
    switch (stack.slot[stack.top]) {
    case 0:
        if (b == 0)
            return false;
        if (b->Id() == DAT_004e0a00) {
            stack.FUN_000f9700(1);
        } else {
            if (!(b->Id() == DAT_004e0a18))
                return false;
            stack.FUN_000f9700(2);
        }
        break;
    case 1: {
        __int64 id = b->Id();
        Node *n = index.FUN_000f9670((int)id, (int)(id >> 32));
        while (n != 0) {
            if (current != 0) {
                if (current->head == 0)
                    current->head = n->Clone();
                else
                    current->head->FUN_000f9b40(n->Clone());
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
        current = (Current *)index.FUN_000f96b0((int)id, (int)(id >> 32));
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
            stack.FUN_000f9700(1);
            break;
        }
        if (FUN_00344e74(a1, 0, DAT_004a13e4, DAT_004a1888, 0) != 0) {
            if (depth > 0) {
                depth--;
            } else {
                stack.FUN_000f9720();
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
        current->head->FUN_000f9b40(a1);
        return result;
    default:
        return false;
    }
    delete a1;
    return result;
}
