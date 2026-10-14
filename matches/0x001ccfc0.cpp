class Obj {
  public:
    char pad[0x1498];
    int values[4];
    void Set(int index, int value);
};

void Obj::Set(int index, int value) {
    if (index >= 0 && index < 4)
        values[index] = value;
}
