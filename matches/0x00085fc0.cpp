extern const float scale;
class Timer {
  public:
    char pad[0x28];
    unsigned __int64 ticks;
    double GetTime();
};
double Timer::GetTime() {
    return (double)ticks * scale;
}