struct Object {
    int FUN_002e16f0(int value, int* output);
    int FUN_002e18c0(int value);
};

int Object::FUN_002e18c0(int value) {
    int output = 0;
    return FUN_002e16f0(value, &output);
}
