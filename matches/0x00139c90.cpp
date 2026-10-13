struct Obj {
    char pad[0x18];
    char* Get();
};
char* Obj::Get() {
    return (char*)((char*)pad + 0x18);
}
