struct Obj {
    char pad[0x38];
    void* Get();
};
void* Obj::Get() {
    return (void*)((char*)this + 0x38);
}
