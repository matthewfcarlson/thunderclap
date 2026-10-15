extern const float scale;
class Obj {
  public:
    char pad[24];
    unsigned __int64 ticks;
    double Get();
};
double Obj::Get() {
    return (double)ticks * scale;
}