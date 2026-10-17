// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 8/8)
// FUN_0024a4a0 @ 0x0024a4a0
struct Link { Link* next; };
struct Node {
    virtual void FUN_0024a450(int);
    Link link;
};
struct List {
    Link* first;
    Link end;
};
void __cdecl FUN_0024a1c0(List*, Node*);
void __cdecl FUN_0024a4a0(List* list) {
    while (list->first != &list->end) {
        Link* last = list->first;
        while (last->next != &list->end)
            last = last->next;
        Node* node = reinterpret_cast<Node*>(reinterpret_cast<char*>(last) - 4);
        if (!node) break;
        FUN_0024a1c0(list, node);
        node->FUN_0024a450(1);
    }
}