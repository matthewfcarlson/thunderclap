class C {
    char pad[0xabc];

  public:
    int values[32];
    int count;
    void Add(int);
};
void C::Add(int value) {
    if (count < 0x20) {
        values[count] = value;
        ++count;
    }
}