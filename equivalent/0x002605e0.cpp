// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 4/4)
// FUN_002605e0 @ 0x002605e0
// audio::SeqEventType constructor: base type registration, own vtable, then insertion into the global type tree.
// equiv-map: ??0Type@om@@QAE@PAX0HH@Z = 0x002584d0
inline void *operator new(unsigned int, void *p) { return p; }
unsigned __int64 __cdecl FUN_002672f0(const char *name, int a, int b);

struct Key_2605e0 {
    unsigned int lo, hi;
};

struct String {
    char data[8];
    void FUN_00240170(const char *s);
};

struct Node {
    Node *left;
    Node *right;
    Node *parent;
    int color;
    String key;
};

struct Tree_2605e0 {
    Node *root;
    Node nil;
};

char __cdecl FUN_002601d0(Tree_2605e0 *tree, void *elem, String *key);

extern int DAT_004e7a2c;
extern Tree_2605e0 *DAT_004cd380;

namespace om {
class Type {
public:
    virtual void v0();
    char data[0x44];
    Type() throw() {}
    Type(Key_2605e0 *key, void *b, int c, int d) throw();
};
}

namespace audio {
class SeqEventType : public om::Type {
public:
    virtual void v0();
    Node node;
    SeqEventType() throw() {}
    SeqEventType *FUN_002605e0(const char *name, void *b, int c, int d);
};

SeqEventType *SeqEventType::FUN_002605e0(const char *name, void *b, int c, int d)
{
    Key_2605e0 key;
    unsigned __int64 k = FUN_002672f0("Data_Sequence", 0, 0);
    key.lo = (unsigned int)k;
    key.hi = (unsigned int)(k >> 32);
    new (this) om::Type(&key, b, c, d);
    new (this) SeqEventType;
    node.key.FUN_00240170(name);
    Tree_2605e0 *tree = DAT_004cd380;
    if (DAT_004e7a2c == 0 && tree) {
        Node *nil = &tree->nil;
        nil->left = nil;
        tree->nil.right = nil;
        tree->nil.parent = nil;
        tree->nil.color = 0;
        tree->root = nil;
    }
    FUN_002601d0(tree, this, &node.key);
    DAT_004e7a2c++;
    return this;
}
}
