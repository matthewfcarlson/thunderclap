struct T_5d130 {
    char pad[0x10];
    int value;
    char FUN_0005d130(int a) {
        value = a;
        return 1;
    }
};

int main() {
    T_5d130 t;
    return t.FUN_0005d130(0);
}