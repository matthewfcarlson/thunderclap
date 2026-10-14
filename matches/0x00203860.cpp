struct Thing_203860 {
    char pad[0xaa4];
    void* Get();
};
void* Thing_203860::Get() {
    return (char*)this + 0xaa4;
}