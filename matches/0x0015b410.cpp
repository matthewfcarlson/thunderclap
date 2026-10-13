class Obj {
  public:
    virtual ~Obj() {}
    char pad[0x28];
    int value;
    int* GetValue();
};
int* Obj::GetValue() {
    return (int*)((char*)this + 0x28);
}