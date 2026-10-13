struct T {
    char pad[0x60];
    void* Get();
};
void* T::Get() {
    return (char*)this + 0x60;
}