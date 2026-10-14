class Obj_12680 {
  public:
    char pad[0x20];
    void* member;
    void* Get();
};
void* Obj_12680::Get() {
    return &member;
}