extern const float gZero_3ebb0;
extern const float gOne_3ebb0;

class ClampOwner {
  public:
    char pad[0x1e58];
    float mValue;
    int mKey;
    float Get(int key);
};

float ClampOwner::Get(int key) {
    float value = mValue;
    if (key != mKey)
        return gZero_3ebb0;
    if (value >= gZero_3ebb0 && value <= gOne_3ebb0)
        return value;
    if (value > gOne_3ebb0)
        return gOne_3ebb0;
    return gZero_3ebb0;
}
