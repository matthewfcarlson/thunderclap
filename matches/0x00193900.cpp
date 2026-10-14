struct Obj_193900 {
    char pad[0x40];
    char* Data();
};
char* Obj_193900::Data() {
    return (char*)((char*)this + 0x40);
}
