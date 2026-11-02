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
extern "C" void __cdecl FUN_0024a1c0(void *, void *);
extern "C" void __cdecl FUN_0024a4a0(void * list_) {
    List * list = (List *)list_;
    while (list->first != &list->end) {
        Link* last = list->first;
        while (last->next != &list->end)
            last = last->next;
        Node* node = reinterpret_cast<Node*>(reinterpret_cast<char*>(last) - 4);
        if (!node) break;
        FUN_0024a1c0((List *)list, (Node *)node);
        node->FUN_0024a450(1);
    }
}