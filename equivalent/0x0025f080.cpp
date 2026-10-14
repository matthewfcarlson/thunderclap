// STATUS: equivalent (tools/equiv.py level 3: 97 inputs, branch coverage 15/16, incomplete)
// FUN_0025f080 @ 0x0025f080
struct Link_25f080 {
    Link_25f080* left;
    Link_25f080* right;
    char pad08[0x20];
    const char* key;      // 0x28
};
struct Entry_25f080 {
    int header;
    Link_25f080 link;            // tree links start at +4
};
struct Tree_25f080 {
    Link_25f080* root;
    Link_25f080 end;             // sentinel at +4
};
struct Key_25f080 { const char* text; };

// Looks a name up in a string-keyed ordered map; returns the entry or null.
Entry_25f080* FUN_0025f080(Tree_25f080* tree, Key_25f080* name)
{
    Link_25f080* node = tree->root;
    Link_25f080* end = &tree->end;
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
            return reinterpret_cast<Entry_25f080*>(reinterpret_cast<char*>(node) - 4);
    } while (node != end);
    return 0;
}
