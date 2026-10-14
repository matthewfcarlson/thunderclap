class Obj_68480 {
  public:
    char pad[0x24];
    float mValue;
    char Set(float angle);
};

char Obj_68480::Set(float angle) {
    mValue = angle * (float)(3.14159265358979323846f / 180.0f);
    return 1;
}
