struct Obj_1822d0 {
    Obj_1822d0* a();
    Obj_1822d0* b();
    unsigned int c();
    unsigned int d(int);
};
struct State_1822d0 {
    char pad[0x10];
    int value;
};
struct PropDropAction {
    char pad[0x1c];
    State_1822d0* state;
    Obj_1822d0* thing;
    bool vfunc_3(int, int);
};
bool PropDropAction::vfunc_3(int x, int y) {
    if (thing) {
        Obj_1822d0* p = thing->a();
        p = p->b();
        int n = state->value;
        if (n < 0) {
            p->c();
            return false;
        }
        p->d(n);
    }
    return false;
}