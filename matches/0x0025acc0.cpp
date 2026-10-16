struct Obj {
    void DoThing(void*, int, int, int);
};
void Target(Obj* volatile* a, void* b) {
    Obj* obj = *a;
    obj->DoThing(b, 8, 1, 1);
}