extern const float gZero;
extern const float gOne;

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
        return gZero;
    if (value >= gZero && value <= gOne)
        return value;
    if (value > gOne)
        return gOne;
    return gZero;
}
