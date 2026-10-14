// Same code shape as 0x00091d50 (propagated; names are from that function)
struct Obj_306f50 {
    char pad[0x68];
    Obj_306f50* Get();
};
Obj_306f50* Obj_306f50::Get() {
    return (Obj_306f50*)((char*)this + 0x68);
}