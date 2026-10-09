extern const float gZero;
class C {
  public:
    char pad[0x12];
    unsigned char flag;
    char pad2;
    float value;
    float Get();
};
float C::Get() {
    if (flag)
        return gZero;
    return value;
}