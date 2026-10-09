struct C { void run(void*); };
struct B { char pad[0x3c]; C* next; };
struct A { char pad[0x0c]; B* child; };
extern A* g;
void __fastcall target(void* p) {
    A* a = g;
    if (a && a->child && a->child->next) a->child->next->run(p);
}