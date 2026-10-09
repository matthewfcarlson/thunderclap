struct Helper {
    int First();
    void Second();
};
struct RoutAction {
    char pad[0x38];
    Helper* ptr;
    void vfunc_4();
};
void RoutAction::vfunc_4() {
    if (ptr) {
        Helper* h = ptr;
        h = (Helper*)h->First();
        h->Second();
    }
}