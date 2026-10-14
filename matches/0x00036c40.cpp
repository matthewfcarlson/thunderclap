class Obj_36c40 {
    char pad[0x1d84];
    unsigned int slots[0x20];

  public:
    void Set(unsigned int index, unsigned int value);
};
void Obj_36c40::Set(unsigned int index, unsigned int value) {
    if (index < 0x20)
        slots[index] = value;
}