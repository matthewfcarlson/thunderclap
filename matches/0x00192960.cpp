class Obj_192960 {
    char pad[0x54];

  public:
    float rads;
    char SetRads(float deg);
};

char Obj_192960::SetRads(float deg) {
    rads = deg * 0.017453293f;
    return 1;
}
