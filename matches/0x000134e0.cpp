class C_134e0 {
  public:
    char pad[0xfc];
    int value;
    int target();
};
int C_134e0::target() {
    return value == 2 || value == 3;
}