typedef unsigned int U;
struct Node { U a,b; Node* owner; Node* prev; Node* next; U fiber; U state1; U state2; U state3; };
struct List { char pad[0x30]; Node* first; Node* last; };
List* GetList();
extern "C" U __stdcall CreateFiber(U, void*, void*);
void __cdecl FUN_0026dd10(Node* p, U a, U b, U c, U d) {
 p->state3=0; p->a=a; p->b=b;
 List* l=GetList(); p->owner=(Node*)l;
 if (!l->first) { l->first=p; p->next=0; }
 else { l->last->prev=p; p->next=l->last; }
 l->last=p; p->prev=0;
 U r=CreateFiber(d,(void*)0x26dc20,p);
 p->state2=0; p->state1=0; p->fiber=r;
}
