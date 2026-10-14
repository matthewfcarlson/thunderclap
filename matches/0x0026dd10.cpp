typedef unsigned int U_26dd10;
struct Node {
    U_26dd10 a, b;
    Node* owner;
    Node* prev;
    Node* next;
    U_26dd10 fiber;
    U_26dd10 state1;
    U_26dd10 state2;
    U_26dd10 state3;
};
struct List_26dd10 {
    char pad[0x30];
    Node* first;
    Node* last;
};
List_26dd10* GetList();
extern "C" U_26dd10 __stdcall CreateFiber(U_26dd10, void*, void*);
void __cdecl FUN_0026dd10(Node* p, U_26dd10 a, U_26dd10 b, U_26dd10 c, U_26dd10 d) {
    p->state3 = 0;
    p->a = a;
    p->b = b;
    List_26dd10* l = GetList();
    p->owner = (Node*)l;
    if (!l->first) {
        l->first = p;
        p->next = 0;
    } else {
        l->last->prev = p;
        p->next = l->last;
    }
    l->last = p;
    p->prev = 0;
    U_26dd10 r = CreateFiber(d, (void*)0x26dc20, p);
    p->state2 = 0;
    p->state1 = 0;
    p->fiber = r;
}
