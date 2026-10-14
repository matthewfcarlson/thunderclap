struct Obj_91d50 {
    char pad[0x68];
    Obj_91d50* Get();
};
Obj_91d50* Obj_91d50::Get() {
    return (Obj_91d50*)((char*)this + 0x68);
}