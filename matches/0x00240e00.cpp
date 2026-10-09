extern "C" {
struct S {
    char pad[0x98];
    float value;
};
extern S* g;
void __cdecl target(float x) {
    g->value = x;
}
}