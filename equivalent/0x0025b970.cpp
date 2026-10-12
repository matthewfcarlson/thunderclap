// STATUS: equivalent (tools/equiv.py level 3: 62 inputs, branch coverage 57/60, incomplete)
// FUN_0025b970 @ 0x0025b970
struct Str {
    char data[12];
    const char* FUN_0023fb00();
    char FUN_00240410(const char* s);
};

struct Stream {
    char pad00[0x24];
    int indent;
};

struct Writer {
    Stream* out;
};

struct Node {
    Node* left;
    Node* right;
    Node* parent;
    int color;
    Str name;
    Str defaultValue;
    Str values[10];
};

struct Tree {
    Node* root;
    Node nil;
};

char FUN_00246f50(Stream* s, const char* fmt, ...);
char FUN_0025ac30(Writer* w, int a, int b);
const char* FUN_00262820(int index);

class Section {
public:
    Tree* tree;
    char pad04[4];
    int dirtyTimeLo;
    int dirtyTimeHi;

    char FUN_0025b970(Writer* w);
};

char Section::FUN_0025b970(Writer* w)
{
    char ok;

    if (!FUN_00246f50(w->out, "[\n")) {
        ok = 0;
    } else {
        w->out->indent++;
        if (!FUN_00246f50(w->out, "DirtyTime : ")) {
            ok = 0;
        } else if (!FUN_0025ac30(w, dirtyTimeLo, dirtyTimeHi)) {
            ok = 0;
        } else if (!FUN_00246f50(w->out, "\n")) {
            ok = 0;
        } else {
            ok = 1;
        }
    }

    if (tree != 0) {
        Node* nil = &tree->nil;
        Node* node = 0;
        Node* first = tree->root;
        if (first != nil) {
            node = first;
            Node* left = node->left;
            if (left != nil) {
                do {
                    node = left;
                    left = node->left;
                } while (left != nil);
            }
        }
        // the original tests the first node for null even after walking down from it; the volatile read
        // keeps the compiler from assuming a dereferenced pointer is non-null
        Node* volatile first_node = node;
        node = first_node;

        while (node != 0) {
            if (ok) {
                Stream* s = w->out;
                if (FUN_00246f50(s, "\"%s\"\n[\n", node->name.FUN_0023fb00())) {
                    w->out->indent++;
                    ok = 1;
                } else {
                    ok = 0;
                }
            }

            if (node->defaultValue.FUN_00240410("")) {
                if (ok) {
                    Stream* s = w->out;
                    if (FUN_00246f50(s, "\"default\" : \"%s\"\n", node->defaultValue.FUN_0023fb00()))
                        ok = 1;
                    else
                        ok = 0;
                }
            }

            for (int i = 0; i < 10; i++) {
                if (node->values[i].FUN_00240410("")) {
                    if (ok) {
                        Stream* s = w->out;
                        const char* value = node->values[i].FUN_0023fb00();
                        if (FUN_00246f50(s, "\"%s\" : \"%s\"\n", FUN_00262820(i), value))
                            ok = 1;
                        else
                            ok = 0;
                    }
                }
            }

            if (ok) {
                w->out->indent--;
                if (FUN_00246f50(w->out, "]\n"))
                    ok = 1;
                else
                    ok = 0;
            } else {
                ok = 0;
            }

            // advance to the in-order successor
            Node* cur = node;
            Node* next = cur->right;
            nil = &tree->nil;
            if (next != nil) {
                while (next->left != nil)
                    next = next->left;
            } else {
                next = cur->parent;
                while (next != nil && cur == next->right) {
                    cur = next;
                    next = next->parent;
                }
            }
            node = (next == nil) ? 0 : next;
        }
    }

    if (ok) {
        w->out->indent--;
        if (FUN_00246f50(w->out, "]\n"))
            return 1;
    }
    return 0;
}
