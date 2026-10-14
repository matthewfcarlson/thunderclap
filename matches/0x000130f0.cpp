class O_130f0 {
  public:
    char pad[0x38];
    int* Get() { return (int*)((char*)this + 0x38); }
};
int* FUN_000130f0(O_130f0* p) {
    return p->Get();
}
