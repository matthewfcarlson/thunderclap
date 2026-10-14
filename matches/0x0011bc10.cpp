class Obj_11bc10 {
  public:
    char Set(float v);
    char pad[0x18];
    float mValue;
};

char Obj_11bc10::Set(float v) {
    mValue = v * 0.01745329252f;
    return 1;
}
