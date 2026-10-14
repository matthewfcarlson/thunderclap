class C_1c96e0 {
    int pad[2];

  public:
    int Get(int i);
};
int C_1c96e0::Get(int i) {
    if (i >= 0 && i < 3)
        return ((int*)this)[2 + i];
    return 0;
}