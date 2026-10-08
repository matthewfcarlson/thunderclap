struct Obj {
    char pad[0x1d4];
    int mValue;
    int GetValue();
};

int Obj::GetValue() {
    return mValue;
}