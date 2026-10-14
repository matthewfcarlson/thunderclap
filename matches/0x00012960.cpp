class Obj_12960 {
  public:
    virtual void* Get();
    char pad[0x44];
    char member;
};
void* Obj_12960::Get() {
    return &member;
}
