class Obj {
    char pad[0x98];
    float value;

  public:
    void Set(float x);
};
void Obj::Set(float x) {
    if (x >= 0.0f && x <= 1.0f)
        value = x;
    else if (x > 1.0f)
        value = 1.0f;
    else
        value = 0.0f;
}