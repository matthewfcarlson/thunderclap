class Thing {
  public:
    int pad[2];
    bool f(int index, int value);
};
bool Thing::f(int index, int value) {
    if (index >= 0 && index < 3) {
        ((int*)this)[2 + index] = value;
        return true;
    }
    return false;
}