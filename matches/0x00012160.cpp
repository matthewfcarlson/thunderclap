struct T {
    char pad[0x58];
    void* f();
};
void* T::f() {
    return (char*)this + 0x58;
}
