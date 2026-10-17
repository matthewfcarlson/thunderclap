// STATUS: equivalent (tools/equiv.py level 3: 539 inputs, branch coverage 14/14)
// FUN_0025f120 @ 0x0025f120
struct Link { Link *left; Link *parent; Link *right; };
struct Entry { int value; Link links; };
struct Iterator { char pad[4]; Link links; };
Entry* __cdecl FUN_0025f120(Entry *end, Iterator *it)
{
    Link *sentinel = &end->links;
    Link *node = it->links.parent;
    if (node != sentinel) {
        while (node->left != sentinel)
            node = node->left;
    } else {
        Link *previous = &it->links;
        node = it->links.right;
        if (node != sentinel) {
            while (node->parent == previous) {
                previous = node;
                node = node->right;
                if (node == sentinel)
                    break;
            }
        }
    }
    if (node == sentinel)
        return 0;
    return reinterpret_cast<Entry*>(reinterpret_cast<char*>(node) - 4);
}
