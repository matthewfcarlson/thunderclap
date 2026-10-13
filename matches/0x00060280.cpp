struct T {
    char pad[0x48];
    void* f();
};
void* T::f() {
    return (char*)this + 0x48;
}