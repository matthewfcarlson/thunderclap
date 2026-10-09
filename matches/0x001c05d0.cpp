extern const float gZero;
class Obj {
  public:
    float value;
    void* ptr;
    char pad08[4];
    char active;
    char up;
    char pad0e[0x42];
    int amount;
    void Tick();
    void Update(float a, float b);
};
void Obj::Update(float a, float b) {
    if (!active || !ptr)
        return;
    if (value < gZero)
        value = 0.0f;
    else
        value = a / b;
    Tick();
    if (up) {
        if (amount >= 255)
            return;
        amount += 10;
        if (amount <= 255)
            return;
        amount = 255;
    } else {
        if (amount <= 0)
            return;
        amount -= 10;
        if (amount >= 0)
            return;
        amount = 0;
    }
}
