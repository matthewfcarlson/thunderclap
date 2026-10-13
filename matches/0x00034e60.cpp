class C {
    char pad[0x18];

  public:
    float Get();
};

float C::Get() {
    return *(float*)((char*)this + 0x18);
}