struct B {
    B* first();
    B* second();
};
struct GrappleStruggleAction {
    char pad[0x20];
    B* member;
    void vfunc_4();
};
void GrappleStruggleAction::vfunc_4() {
    B* p = member->first();
    B* q = p->second();
    *(int*)((char*)q + 0x1e58) = 0;
}