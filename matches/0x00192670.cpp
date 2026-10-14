class Obj_192670 {
  public:
    char pad[0x30];
    float value;
    char Set(float v);
};

char Obj_192670::Set(float v) {
    value = v * 0.017453292f;
    return 1;
}