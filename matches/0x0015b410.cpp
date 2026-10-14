class Obj_15b410 {
  public:
    virtual ~Obj_15b410() {}
    char pad[0x28];
    int value;
    int* GetValue();
};
int* Obj_15b410::GetValue() {
    return (int*)((char*)this + 0x28);
}