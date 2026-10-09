struct A { void* f(); };
struct B { void* g(); };
struct C { void h(int); };
struct IntentionClearAction {
    char pad[0x20];
    A* member;
    bool vfunc_3(int, int);
};
bool IntentionClearAction::vfunc_3(int, int) {
    void* p = member->f();
    p = ((B*)p)->g();
    ((C*)p)->h(1);
    return true;
}
