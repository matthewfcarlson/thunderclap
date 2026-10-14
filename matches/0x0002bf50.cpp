class Thing_2bf50 {
  public:
    bool Check();
    void Run(int count);
};
void Thing_2bf50::Run(int count) {
    int i = 0;
    while (i < count && Check())
        ++i;
}