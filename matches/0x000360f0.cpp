extern float Zero;
class Thing {
  public:
    char pad[0x110];
    float value;
    int count;
    bool Target();
};
bool Thing::Target() {
    if (value > Zero)
        return true;
    return count > 0;
}