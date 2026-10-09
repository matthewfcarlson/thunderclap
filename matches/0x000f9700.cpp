class X {
  public:
    char pad[0x10];
    int count;
    void Add(int x);
};
void X::Add(int x) {
    if (count < 4) {
        ++count;
        *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + count * 4) = x;
    }
}