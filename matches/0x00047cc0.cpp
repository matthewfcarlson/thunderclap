class Obj_47cc0 {
  public:
    char pad[0x10];
    float mVal;
    unsigned char Set(float x);
};
unsigned char Obj_47cc0::Set(float x) {
    mVal = x * 0.017453292f;
    return 1;
}
