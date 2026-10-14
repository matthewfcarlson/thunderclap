struct Sub_1921b0 {
    char data[0x18];
};
struct Obj_1921b0 {
    char pad[0x18];
    Sub_1921b0* Get();
};
Sub_1921b0* Obj_1921b0::Get() {
    return (Sub_1921b0*)((char*)this + 0x18);
}