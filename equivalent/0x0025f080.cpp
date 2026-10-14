// STATUS: equivalent (tools/equiv.py level 3: 97 inputs, branch coverage 15/16, incomplete)
// FUN_0025f080 @ 0x0025f080
struct Link {
    Link* left;
    Link* right;
    char pad08[0x20];
    const char* key;      // 0x28
};
struct Entry {
    int header;
    Link link;            // tree links start at +4
};
struct Tree {
    Link* root;
    Link end;             // sentinel at +4
};
struct Key { const char* text; };

// Looks a name up in a string-keyed ordered map; returns the entry or null.
Entry* FUN_0025f080(Tree* tree, Key* name)
{
    Link* node = tree->root;
    Link* end = &tree->end;
    if (node == end)
        return 0;
    const char* text = name->text;
    do {
        const char* a = text;
        const char* b = node->key;
        int cmp;
        for (;;) {
            unsigned char ca = *a;
            unsigned char cb = *b;
            if (ca != cb) {
                cmp = ca < cb ? -1 : 1;
                break;
            }
            if (ca == 0) {
                cmp = 0;
                break;
            }
            a++;
            b++;
        }
        if (cmp < 0)
            node = node->left;
        else if (cmp > 0)
            node = node->right;
        else
            return reinterpret_cast<Entry*>(reinterpret_cast<char*>(node) - 4);
    } while (node != end);
    return 0;
}
