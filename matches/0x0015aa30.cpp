class Obj_15aa30 {
  public:
    char pad[0x60];
    int m;
    int* Get();
};
int* Obj_15aa30::Get() {
    return &m;
}