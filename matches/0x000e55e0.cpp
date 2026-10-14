class C_e55e0 {
    char pad[0xabc];

  public:
    int values[32];
    int count;
    void Add(int);
};
void C_e55e0::Add(int value) {
    if (count < 0x20) {
        values[count] = value;
        ++count;
    }
}