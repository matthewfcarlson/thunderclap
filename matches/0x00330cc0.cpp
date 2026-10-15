class Thing {
  public:
    char pad[0x94];
    void* other;
    char pad2[0x4c];
    int value;
    void update();
    void setValue(int v);
};
void Thing::setValue(int v) {
    if (v != value) {
        value = v;
        if (v < 2)
            v = 2;
        value = v;
        if (other)
            update();
    }
}