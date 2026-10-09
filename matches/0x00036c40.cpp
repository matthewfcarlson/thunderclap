class Obj { char pad[0x1d84]; unsigned int slots[0x20]; public: void Set(unsigned int index, unsigned int value); };
void Obj::Set(unsigned int index, unsigned int value) {
    if (index < 0x20) slots[index] = value;
}