class Thing {
  public:
    bool Check();
    void Run(int count);
};
void Thing::Run(int count) {
    int i = 0;
    while (i < count && Check())
        ++i;
}