class O {
  public:
    char pad[0x38];
    int* Get() { return (int*)((char*)this + 0x38); }
};
int* FUN_000130f0(O* p) {
    return p->Get();
}
