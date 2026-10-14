struct B_147cf0 {
    B_147cf0* first();
    B_147cf0* second();
};
struct GrappleStruggleAction {
    char pad[0x20];
    B_147cf0* member;
    void vfunc_4();
};
void GrappleStruggleAction::vfunc_4() {
    B_147cf0* p = member->first();
    B_147cf0* q = p->second();
    *(int*)((char*)q + 0x1e58) = 0;
}