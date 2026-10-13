struct Obj {
    char pad[0x40];
    char* Data();
};
char* Obj::Data() {
    return (char*)((char*)this + 0x40);
}
