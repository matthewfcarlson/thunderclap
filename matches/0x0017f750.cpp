class Obj_17f750 {
  public:
    char pad[0x18];
    char* mPtr;
    char** Get();
};

char** Obj_17f750::Get() {
    return &mPtr;
}
