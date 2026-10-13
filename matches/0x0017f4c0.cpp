class Obj {
  public:
    char pad[0x18];
    int mVal;
    int* Get();
};

int* Obj::Get() {
    return &mVal;
}