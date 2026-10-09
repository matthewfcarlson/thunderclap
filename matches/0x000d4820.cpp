class Obj {
    char pad[0x594];
    float items[3][67];

  public:
    void Set(int index, float value);
};
void Obj::Set(int index, float value) {
    if (index >= 0 && index < 3)
        items[index][0] = value;
}