class Obj {
  public:
    char pad[12];
    char data[15];
    void Set(int index, char value);
};
void Obj::Set(int index, char value) {
    if (index >= 0 && index < 15)
        data[index] = value;
}