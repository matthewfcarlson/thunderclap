// STATUS: equivalent (tools/equiv.py level 3: 3015 inputs, branch coverage 13/14, incomplete)
// FUN_00233b30 @ 0x00233b30
class Node;

class Node {
public:
    virtual void OnAttached();
    char pad04[0x14 - 4];
    class List_233b30* owner;      // 0x14
    char pad18[0x20 - 0x18];
    Node* next;             // 0x20
};

class List_233b30 {
public:
    char pad0[0x1c];
    Node* head;             // 0x1c
    int FUN_00233160(Node* node);
    int FUN_00233b30(int index, Node* node);
};

// Inserts node at the given position (end if past the last); negative index appends via FUN_00233160.
int List_233b30::FUN_00233b30(int index, Node* node)
{
    if (node == 0)
        return -1;
    if (index < 0)
        return FUN_00233160(node);
    Node* cur = head;
    Node* prev = 0;
    int i = 0;
    while (cur != 0 && i < index) {
        prev = cur;
        cur = cur->next;
        i++;
    }
    if (prev != 0)
        prev->next = node;
    else
        head = node;
    node->owner = this;
    node->next = cur;
    node->OnAttached();
    return i;
}
