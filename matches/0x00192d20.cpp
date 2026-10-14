class Obj_192d20 {
  public:
    char pad[0xf4];
    float value;
    bool Set(float angle);
};

bool Obj_192d20::Set(float angle) {
    value = angle * 0.017453292519943f;
    return true;
}
