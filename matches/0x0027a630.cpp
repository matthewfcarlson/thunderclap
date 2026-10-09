class Slot {
  public:
    char pad[8];
    void Init();
};
class Target {
  public:
    Slot slots[20];
    int values[21];
    Target* Fn();
};
Target* Target::Fn() {
    for (int i = 0; i < 20; ++i)
        slots[i].Init();
    values[20] = 0;
    for (int j = 0; j < 20; ++j)
        values[j] = 0;
    return this;
}