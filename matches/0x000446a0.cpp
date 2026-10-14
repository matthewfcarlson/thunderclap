extern const float gZero_446a0;
class C_446a0 {
    char pad[0xd0];

  public:
    float Get(int index);
};
float C_446a0::Get(int index) {
    if (index == 0)
        return gZero_446a0;
    return *(float*)((char*)this + 0xd0 + index * 4);
}