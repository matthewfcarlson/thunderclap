extern const float scale;
class Counter {
  public:
    char pad[0x20];
    unsigned __int64 value;
    double Get();
};
double Counter::Get() {
    return (double)value * scale;
}