class Thing {
  public:
    char pad[12];
    void* value;
    void Run(unsigned int);
};
extern "C" void* __cdecl FUN_00240750();
extern "C" void __cdecl FUN_002416c0(void*, void*, float);
void Thing::Run(unsigned int n) {
    if (FUN_00240750()) {
        void* p = FUN_00240750();
        FUN_002416c0(p, value, (float)n);
    }
}