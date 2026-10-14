struct A_15cbb0 {
    void* x;
    void* GetThing();
};
struct B_15cbb0 {
    void* GetNext();
};
struct C_15cbb0 {
    void DoThing(int);
};
class LocomotingAction {
  public:
    char pad[0x1c];
    A_15cbb0* member;
    void vfunc_4();
};
void LocomotingAction::vfunc_4() {
    A_15cbb0* p = member;
    if (p) {
        B_15cbb0* q = (B_15cbb0*)p->GetThing();
        if (q) {
            C_15cbb0* r = (C_15cbb0*)q->GetNext();
            if (r)
                r->DoThing(0);
        }
    }
}