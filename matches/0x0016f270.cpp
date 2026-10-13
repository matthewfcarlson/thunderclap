struct Obj {
    char pad[0x18];
    void* Get();
};

void* Obj::Get() {
    return (char*)this + 0x18;
}
