// STATUS: equivalent (tools/equiv.py level 3: 532 inputs, branch coverage 14/14)
// FUN_002604d0 @ 0x002604d0
struct Node { Node* left; Node* parent; Node* right; };
struct Entry { char pad[0x48]; Node node; };
struct Head { char pad[4]; Node sentinel; };
Entry* __cdecl FUN_002604d0(Head* head, Entry* entry)
{
    Node* end = &head->sentinel;
    Node* current = entry->node.parent;
    if (current != end) {
        while (current->left != end)
            current = current->left;
    } else {
        Node* child = entry->node.right;
        if (child == end)
            return 0;
        Node* previous = &entry->node;
        while (previous == child->parent) {
            previous = child;
            child = child->right;
            if (child == end)
                break;
        }
        current = child;
    }
    return current == end ? 0 : (Entry*)((char*)current - 0x48);
}