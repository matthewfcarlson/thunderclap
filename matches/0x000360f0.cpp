extern float Zero_360f0;
class Thing_360f0 {
  public:
    char pad[0x110];
    float value;
    int count;
    bool Target();
};
bool Thing_360f0::Target() {
    if (value > Zero_360f0)
        return true;
    return count > 0;
}