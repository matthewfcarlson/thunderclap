// Same code shape as 0x00091d50 (propagated; names are from that function)
struct Obj_306f60 {
    char pad[0x68];
    Obj_306f60* Get();
};
Obj_306f60* Obj_306f60::Get() {
    return (Obj_306f60*)((char*)this + 0x68);
}