struct Helper_11cac0 {
    int First();
    void Second();
};
struct RoutAction {
    char pad[0x38];
    Helper_11cac0* ptr;
    void vfunc_4();
};
void RoutAction::vfunc_4() {
    if (ptr) {
        Helper_11cac0* h = ptr;
        h = (Helper_11cac0*)h->First();
        h->Second();
    }
}