struct T_60280 {
    char pad[0x48];
    void* f();
};
void* T_60280::f() {
    return (char*)this + 0x48;
}