struct Sub {};
struct Obj {
    char pad[0x18];
    Sub* Get();
};
Sub* Obj::Get() {
    return (Sub*)((char*)this + 0x18);
}