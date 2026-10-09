struct Obj {
    char pad[0xa0];
    int value;
    bool IsTwo();
};
bool Obj::IsTwo() {
    if (value == 2)
        return true;
    return false;
}
