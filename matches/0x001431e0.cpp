struct Sub_1431e0 {
    char b[0x28];
};
struct Obj_1431e0 {
    Sub_1431e0* Get();
};
Sub_1431e0* Obj_1431e0::Get() {
    return (Sub_1431e0*)((char*)this + 0x28);
}
