typedef unsigned int uint;
void __cdecl ReleaseThing(uint);
struct Obj_b0710 {
    uint a;
    uint b;
    void Clear();
};
void Obj_b0710::Clear() {
    if (b) {
        ReleaseThing(b);
        a = 0;
        b = 0;
    }
}