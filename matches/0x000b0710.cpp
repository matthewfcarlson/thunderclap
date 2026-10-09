typedef unsigned int uint;
void __cdecl ReleaseThing(uint);
struct Obj { uint a; uint b; void Clear(); };
void Obj::Clear() {
    if (b) {
        ReleaseThing(b);
        a = 0;
        b = 0;
    }
}