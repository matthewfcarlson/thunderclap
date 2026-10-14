// Same code shape as 0x000b0710 (propagated; names are from that function)
typedef unsigned int uint;
void __cdecl ReleaseThing(uint);
struct Obj_b0ff0 {
    uint a;
    uint b;
    void Clear();
};
void Obj_b0ff0::Clear() {
    if (b) {
        ReleaseThing(b);
        a = 0;
        b = 0;
    }
}