class Target {
  public:
    char pad[0xb8];
    float* values;
    float get(int index);
};
float Target::get(int index) {
    return values[index];
}