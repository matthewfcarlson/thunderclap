class C_2287a0 {
    char pad[0x854];

  public:
    float Get(int i);
};
float C_2287a0::Get(int i) {
    return ((float*)(pad + 0x854))[i];
}