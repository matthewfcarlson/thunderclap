struct Obj {
    char pad[0xa8];
    void* Get();
};
void* Obj::Get() {
    return (char*)this + 0xa8;
}