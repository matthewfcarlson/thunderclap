// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 10/10)
// audio::SeqEventNestTrack::vfunc_2 @ 0x0024e870
// audio::SeqEventNestTrack::vfunc_2: find the nested event for a key and forward to it
// equiv-map: ??0Key@@QAE@XZ = 0x0023fac0
// equiv-map: ??1Key@@QAE@XZ = 0x00240060
struct Key {
    char data[12];
    Key() throw();
    ~Key() throw();
    unsigned int FUN_0023fb00() throw();
};

struct Event;

struct Handler {
    virtual void v0();
    virtual void v1();
    virtual void v2(Event *e);
};

struct Node {
    Node *left;
    Node *right;
    char pad08[0x10];
    Handler handler;
    char pad1c[0x34 - 0x1c];
    unsigned int key;
};

struct Index {
    char pad00[0x28];
    Node *root;
    char nil[1];
};

struct Context {
    char pad00[0x5c];
    char tree[1];
};

struct Event {
    char pad00[0x3c];
    Context *ctx;
};

void __cdecl FUN_002613b0(void *tree, Key *key, void *name) throw();
Index *__cdecl FUN_00247810(Context *c) throw();
unsigned int __cdecl FUN_002673a0(unsigned int v, int flags) throw();

class SeqEventNestTrack {
public:
    char pad00[8];
    char name[1];

    void FUN_0024e870(Event *e) throw();
};

void SeqEventNestTrack::FUN_0024e870(Event *e) throw()
{
    Key key;
    FUN_002613b0(e->ctx->tree, &key, name);
    Index *index = FUN_00247810(e->ctx);
    unsigned int id = FUN_002673a0(key.FUN_0023fb00(), 0);
    Node *node = index->root;
    while (node != (Node *)index->nil) {
        if (id < node->key) {
            node = node->left;
        } else if (id <= node->key) {
            Node *hit = (Node *)((char *)node - 4);
            if (hit != 0)
                node->handler.v2(e);
            break;
        } else {
            node = node->right;
        }
    }
}
