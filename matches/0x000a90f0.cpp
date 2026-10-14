class Thing_a90f0 {
  public:
    char pad[0x154];
    int values[3];
    void set(int index, int value);
};
void Thing_a90f0::set(int index, int value) {
    values[index * 3] = value;
}