struct ThingB {};
struct ThingA { ThingB* next(); };
struct Start { ThingA* get(); };
class CMotionHitGroundHeightAction {
public:
    char pad[0x1c];
    Start* member1c;
    void* member20;
    bool vfunc_7(unsigned int);
};
bool CMotionHitGroundHeightAction::vfunc_7(unsigned int arg) {
    ThingA* a = member1c->get();
    ThingB* b = a->next();
    *(void**)((char*)b + 0x148) = member20;
    return true;
}