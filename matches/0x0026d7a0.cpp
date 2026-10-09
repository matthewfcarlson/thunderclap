extern void __stdcall DeleteFiber(void *);
extern int gSpecial;
struct Node { char pad[8]; Node *parent; Node *prev; Node *next; void *fiber; };
void __cdecl unlinkNode(Node *p) {
    if (p != (Node*)&gSpecial && p != (Node*)((char*)p->parent + 8)) DeleteFiber(p->fiber);
    Node *parent = p->parent;
    if (p->next == 0) *(Node**)((char*)parent + 0x30) = p->prev;
    else *(Node**)((char*)p->next + 0x0c) = p->prev;
    if (p->prev == 0) {
        *(Node**)((char*)parent + 0x34) = p->next;
        return;
    }
    *(Node**)((char*)p->prev + 0x10) = p->next;
}