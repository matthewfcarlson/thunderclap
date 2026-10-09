class C {
    char pad[0x854];

  public:
    float Get(int i);
};
float C::Get(int i) {
    return ((float*)(pad + 0x854))[i];
}