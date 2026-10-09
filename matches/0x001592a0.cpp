struct CollisionTargetPriorityCondition {
    int* vptr;
    int pad4;
    int pad8;
    int mC;
    int m10;
    void Init(int);
};
extern void* __cdecl Alloc(int);
void* __cdecl Factory_vfunc5() {
    CollisionTargetPriorityCondition* p = (CollisionTargetPriorityCondition*)Alloc(0x14);
    if (p) {
        p->Init(0);
        p->vptr = (int*)0x414010;
        p->mC = 0;
        p->m10 = 0;
        return p;
    }
    return 0;
}