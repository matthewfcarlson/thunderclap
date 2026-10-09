struct Obj {
    char pad[0xe0];
    int values[1];
    bool Check(int);
    int Lookup(int);
};
bool Obj::Check(int x) {
    int i = Lookup(x);
    if (i == -1)
        return false;
    return values[i] == 1;
}