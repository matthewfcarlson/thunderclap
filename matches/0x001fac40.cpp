class C_1fac40 {
    char pad[8];
    int count;
    int items[1];

  public:
    void Add(int x);
};
void C_1fac40::Add(int x) {
    items[count] = x;
    ++count;
}