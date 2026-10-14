extern const float gZero_fc830;
class C_fc830 {
  public:
    char pad[0x12];
    unsigned char flag;
    char pad2;
    float value;
    float Get();
};
float C_fc830::Get() {
    if (flag)
        return gZero_fc830;
    return value;
}