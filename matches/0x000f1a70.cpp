class Obj {
  public:
    char pad[0x150];
    float value;
    char pad2[8];
    float low;
    float high;
    void update();
    void set(float x);
};
void Obj::set(float x) {
    if (x >= low && x <= high) {
        value = x;
        update();
    }
}