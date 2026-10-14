struct T_17fdf0 {
    char pad[0x60];
    void* Get();
};
void* T_17fdf0::Get() {
    return (char*)this + 0x60;
}