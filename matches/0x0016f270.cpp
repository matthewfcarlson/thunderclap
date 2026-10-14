struct Obj_16f270 {
    char pad[0x18];
    void* Get();
};

void* Obj_16f270::Get() {
    return (char*)this + 0x18;
}
