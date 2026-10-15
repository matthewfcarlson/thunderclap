extern const float scale;
class Clock {
    char pad[16];

  public:
    unsigned __int64 count;
    double Get();
};
double Clock::Get() {
    return (double)count * scale;
}