struct ScriptHandler_1d27b0 {
    char pad[8];
    int value;
    int Fn(int x);
    int Other(int, int);
};
int ScriptHandler_1d27b0::Fn(int x) {
    return Other(x, value);
}