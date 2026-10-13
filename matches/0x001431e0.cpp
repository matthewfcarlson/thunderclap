struct Sub {
    char b[0x28];
};
struct Obj {
    Sub* Get();
};
Sub* Obj::Get() {
    return (Sub*)((char*)this + 0x28);
}
