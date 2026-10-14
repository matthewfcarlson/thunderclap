struct Obj_12c80 {
    char pad[0xa8];
    void* Get();
};
void* Obj_12c80::Get() {
    return (char*)this + 0xa8;
}