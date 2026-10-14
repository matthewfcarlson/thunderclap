class Obj_17f4c0 {
  public:
    char pad[0x18];
    int mVal;
    int* Get();
};

int* Obj_17f4c0::Get() {
    return &mVal;
}