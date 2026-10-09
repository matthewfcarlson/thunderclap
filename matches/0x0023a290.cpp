struct Action {
    void target();
};
struct QueuedNodeAction {
    char pad[0x2c];
    void vfunc_4();
};
void QueuedNodeAction::vfunc_4() {
    ((Action*)((char*)this + 0x2c))->target();
}