class C_1c3810 {
  public:
    char pad[0x14];
    C_1c3810* p;
    void target(int, int, int, int);
    void helper(int, int, int, int);
};
void C_1c3810::target(int a, int b, int c, int d) {
    C_1c3810* q = p;
    if (q)
        q->helper(a, b, c, d);
}