struct Obj {
    char pad[0x38];
    void* Get();
};
void* Obj::Get() {
    return (char*)this + 0x38;
}
