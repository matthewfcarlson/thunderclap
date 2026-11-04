struct Sub_68b60 {};
struct Obj_68b60 {
    char pad[0x18];
    Sub_68b60* GetHint_00068b60();
};
Sub_68b60* Obj_68b60::GetHint_00068b60() {
    return (Sub_68b60*)((char*)this + 0x18);
}