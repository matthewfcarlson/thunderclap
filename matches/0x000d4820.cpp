class Obj_d4820 {
    char pad[0x594];
    float items[3][67];

  public:
    void Set(int index, float value);
};
void Obj_d4820::Set(int index, float value) {
    if (index >= 0 && index < 3)
        items[index][0] = value;
}