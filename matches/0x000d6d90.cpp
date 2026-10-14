class Slots_d6d90 {
  public:
    char pad[12];
    int values[8];
    float Add(int value);
};
float Slots_d6d90::Add(int value) {
    int i = 0;
    do {
        if (values[i] == 0) {
            values[i] = value;
            return (float)(i + 1) * 0.01f;
        }
        ++i;
    } while (i < 8);
    return (float)(i + 1) * 0.01f;
}
