struct Obj {
    int DoThing(void*, int, int, int);
};
int Target(Obj* volatile* a, void* b) {
    Obj* obj = *a;
    return obj->DoThing(b, 8, 1, 1);
}