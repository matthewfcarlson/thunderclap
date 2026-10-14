struct A_171820 {
    void* f();
};
struct B_171820 {
    void* g();
};
struct C_171820 {
    void h(int);
};
struct IntentionClearAction {
    char pad[0x20];
    A_171820* member;
    bool vfunc_3(int, int);
};
bool IntentionClearAction::vfunc_3(int, int) {
    void* p = member->f();
    p = ((B_171820*)p)->g();
    ((C_171820*)p)->h(1);
    return true;
}
