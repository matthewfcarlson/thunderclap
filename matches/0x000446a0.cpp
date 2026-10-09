extern const float gZero;
class C {
    char pad[0xd0];

  public:
    float Get(int index);
};
float C::Get(int index) {
    if (index == 0)
        return gZero;
    return *(float*)((char*)this + 0xd0 + index * 4);
}