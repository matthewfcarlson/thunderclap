class Thing_1c9700 {
  public:
    int pad[2];
    bool f(int index, int value);
};
bool Thing_1c9700::f(int index, int value) {
    if (index >= 0 && index < 3) {
        ((int*)this)[2 + index] = value;
        return true;
    }
    return false;
}