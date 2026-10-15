class Obj {
    char pad[0x10c];
    int count;
    int slots[10];

  public:
    void Add(int v);
};
void Obj::Add(int v) {
    for (int i = 0; i < 10; ++i) {
        if (slots[i] == -1) {
            ++count;
            slots[i] = v;
            return;
        }
    }
}