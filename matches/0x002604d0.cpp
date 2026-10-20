struct Node {
    Node* left;
    Node* parent;
    Node* right;
};
struct Entry {
    char pad[0x48];
    Node node;
};
struct Head {
    char pad[4];
    Node sentinel;
};
Entry* __cdecl FUN_002604d0(Head* head, Entry* entry) {
    Node* previous = &entry->node;
    Node* current = previous->parent;
    Node* end = &head->sentinel;
    if (current != end) {
        while (current->left != end)
            current = current->left;
    } else {
        Node* child = previous->right;
        if (child == end)
            return 0;
        do {
            if (previous != child->parent)
                break;
            previous = child;
            child = child->right;
        } while (child != end);
        current = child;
    }
    return current == end ? 0 : (Entry*)((char*)current - 0x48);
}