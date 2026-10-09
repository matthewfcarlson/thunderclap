struct A {
    void* x;
    void* GetThing();
};
struct B {
    void* GetNext();
};
struct C {
    void DoThing(int);
};
class LocomotingAction {
  public:
    char pad[0x1c];
    A* member;
    void vfunc_4();
};
void LocomotingAction::vfunc_4() {
    A* p = member;
    if (p) {
        B* q = (B*)p->GetThing();
        if (q) {
            C* r = (C*)q->GetNext();
            if (r)
                r->DoThing(0);
        }
    }
}