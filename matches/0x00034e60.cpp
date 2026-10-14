class C_34e60 {
    char pad[0x18];

  public:
    float Get();
};

float C_34e60::Get() {
    return *(float*)((char*)this + 0x18);
}