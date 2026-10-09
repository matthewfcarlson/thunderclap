// Same code shape as 0x000df5e0 (propagated; names are from that function)
typedef unsigned int U;
void __cdecl Helper(U);
struct Target {
    U a;
    U b;
    void Run();
};
void Target::Run() {
    Helper(a);
    Helper(b);
}