struct Obj_1399f0 {
    char pad[0x10];
    void* Get();
};

void* Obj_1399f0::Get() {
    return (char*)this + 0x10;
}
