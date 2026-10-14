// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 4/4)
// FUN_001f9530 @ 0x001f9530
struct Id64_1f9530 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af30(const Id64_1f9530 *src);
};

// An entry description: an id followed by two flag bytes and a 16-bit value.
struct KeyInfo {
    Id64_1f9530 id;                // 0x00
    char flagA;             // 0x08
    char flagB;             // 0x09
    char pad0a[6];
    unsigned short value;   // 0x10
};

struct Node {
    char pad00[0x10];
    KeyInfo info;           // 0x10
    char pad_end[0x28 - 0x10 - 0x12];
};

class Allocator {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void *vfunc_3(unsigned int size);
};

extern char FUN_001f92b0;
extern char FUN_001f92f0;

struct Handle_1f9530 {
    Node *node;
    class Registry_1f9530 *owner;
};

class Registry_1f9530 {
public:
    char pad00[0x18];
    Allocator *allocator;   // 0x18
    void *FUN_00230be0(void *matcher, const KeyInfo *key);
    void FUN_00230c30(Node *node, void *init, void *found);
    Handle_1f9530 *FUN_001f9530(Handle_1f9530 *out, const KeyInfo *key);
};

Handle_1f9530 *Registry_1f9530::FUN_001f9530(Handle_1f9530 *out, const KeyInfo *key)
{
    void *found = FUN_00230be0(&FUN_001f92f0, key);
    if (found == 0) {
        out->node = 0;
        out->owner = 0;
        return out;
    }

    Node *node = (Node *)allocator->vfunc_3(0x28);
    if (node != 0) {
        KeyInfo *copy = &node->info;
        copy->id.FUN_0027af30(&key->id);
        copy->flagA = key->flagA;
        copy->flagB = key->flagB;
        copy->value = key->value;
    }
    FUN_00230c30(node, &FUN_001f92b0, found);

    out->node = node;
    out->owner = this;
    return out;
}
