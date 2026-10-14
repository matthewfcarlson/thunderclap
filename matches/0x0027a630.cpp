class Slot_27a630 {
  public:
    char pad[8];
    void Init();
};
class Target_27a630 {
  public:
    Slot_27a630 slots[20];
    int values[21];
    Target_27a630* Fn();
};
Target_27a630* Target_27a630::Fn() {
    for (int i = 0; i < 20; ++i)
        slots[i].Init();
    values[20] = 0;
    for (int j = 0; j < 20; ++j)
        values[j] = 0;
    return this;
}