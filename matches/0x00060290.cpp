class Obj_60290 {
  public:
    char pad[0x50];
    int value;
    int* GetValue();
};

int* Obj_60290::GetValue() {
    return &value;
}
