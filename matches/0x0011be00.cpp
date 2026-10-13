class Thing {
  public:
    char pad[0x14];
    float value;
    float Get();
};

float Thing::Get() {
    return value;
}
