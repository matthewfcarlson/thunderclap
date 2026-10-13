class Obj {
  public:
    char pad[0x50];
    int value;
    int* GetValue();
};

int* Obj::GetValue() {
    return &value;
}
