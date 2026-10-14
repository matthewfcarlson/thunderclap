class Target_1d4ea0 {
  public:
    char pad[0xb8];
    float* values;
    float get(int index);
};
float Target_1d4ea0::get(int index) {
    return values[index];
}