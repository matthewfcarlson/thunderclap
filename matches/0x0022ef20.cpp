struct Sub {
    void Update(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
};
class Obj {
  public:
    unsigned int mCache[67];
    unsigned int mSize, mDiv, mBase;
    char Fn(int index, float value);
};
char Obj::Fn(int index, float value) {
    int i = (int)value;
    if (i == (int)mCache[index])
        return 0;
    unsigned int q = mDiv, b = mBase;
    unsigned int a = ((i + 3) % q) * 16 + b, c = ((i + 2) % q) * 16 + b, d = ((i + 1) % q) * 16 + b,
                 e = (i % q) * 16 + b;
    Sub* sub = (Sub*)((char*)this + 8 + index * 128);
    sub->Update(mSize, e, d, c, a);
    mCache[index] = i;
    return 1;
}