struct Sub_68b60 {};
struct Obj_68b60 {
    char pad[0x18];
    Sub_68b60* Get();
};
Sub_68b60* Obj_68b60::Get() {
    return (Sub_68b60*)((char*)this + 0x18);
}