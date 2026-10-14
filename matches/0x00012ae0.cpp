struct Obj_12ae0 {
    char pad[0x10];
    char* Get();
};
char* Obj_12ae0::Get() {
    return (char*)this + 0x10;
}