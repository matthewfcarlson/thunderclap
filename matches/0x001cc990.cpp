extern const float gDefault;

class FloatArray {
  public:
    char pad[0x10];
    float values[0x40];
    float GetFloat(int index);
};

float FloatArray::GetFloat(int index) {
    if (index >= 0 && index < 0x40)
        return values[index];
    return gDefault;
}
