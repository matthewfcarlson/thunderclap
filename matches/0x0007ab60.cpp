class Obj {
  public:
    char pad[11];
    char data[6408];
    void Set(int n);
};
void Obj::Set(int n) {
    if (n > 0 && n <= 800)
        data[n * 8] = 1;
}