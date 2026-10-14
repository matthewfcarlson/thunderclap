class Obj_16ecc0 {
    char pad[0x20];
    int m;

  public:
    int* Get();
};
int* Obj_16ecc0::Get() {
    return &m;
}
