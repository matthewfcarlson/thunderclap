struct Widget {
    char pad[0x134];
    int mValue;
    int GetValue();
};

int Widget::GetValue() {
    return mValue;
}
