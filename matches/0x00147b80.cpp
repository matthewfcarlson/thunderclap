struct Result { char pad[0x1e58]; float value; int flag; };
struct HelperA { HelperA* f(); };
struct HelperB { Result* g(); };
class Action { public: char pad[0x20]; };
class GrappleStruggleAction : public Action { public: bool vfunc_3(int, int); };
bool GrappleStruggleAction::vfunc_3(int, int) {
    HelperA* a = *(HelperA**)((char*)this + 0x20);
    HelperA* b = a->f();
    Result* r = ((HelperB*)b)->g();
    r->flag = 1;
    r->value = 0.5f;
    return true;
}