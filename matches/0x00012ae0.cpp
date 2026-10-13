struct Obj {
    char pad[0x10];
    char* Get();
};
char* Obj::Get() {
    return (char*)this + 0x10;
}