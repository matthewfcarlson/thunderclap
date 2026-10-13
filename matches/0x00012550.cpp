struct Thing {
    char pad[0x49];
    void* Get();
};
void* Thing::Get() {
    return (char*)this + 0x48;
}