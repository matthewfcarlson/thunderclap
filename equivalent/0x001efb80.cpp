// STATUS: equivalent (tools/equiv.py level 3: 3094 inputs, branch coverage 23/26, incomplete)
// FUN_001efb80 @ 0x001efb80
struct Key_1efb80 {
    unsigned int lo;
    unsigned int hi;
};

struct KeyList_1efb80 {
    Key_1efb80 keys[8];
    int count;
};

struct Node {
    Node *firstChild;
    char pad04[8];
    Node *sibling;
    Key_1efb80 key;
};

class NodeTree {
public:
    char pad00[8];
    Node *root;
    Node *Find(KeyList_1efb80 *path);
};

Node *NodeTree::Find(KeyList_1efb80 *path)
{
    if (path == 0)
        return 0;
    Node *result = root;
    Node *cur = root;
    for (int i = 0; i < path->count; i++) {
        if (cur == 0)
            return result;
        const Key_1efb80 *k = &path->keys[i];
        Node *found = cur;
        if (!(k->lo == cur->key.lo && k->hi == cur->key.hi)) {
            found = cur->firstChild;
            while (found != 0 && !(found->key.lo == k->lo && found->key.hi == k->hi))
                found = found->sibling;
        }
        if (found != 0)
            result = found;
        cur = found;
    }
    return result;
}
