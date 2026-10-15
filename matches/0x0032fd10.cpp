class Obj {
    char pad[0xcc];
    int mode;
    float value;

  public:
    void Set(int x);
};
void Obj::Set(int x) {
    mode = x;
    switch (x) {
    case 0:
    case 2:
        value = 1.0f;
        break;
    case 1:
        value = 0.05f;
        break;
    }
}