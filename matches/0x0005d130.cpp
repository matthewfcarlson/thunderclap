struct T {
    char pad[0x10];
    int value;
    char FUN_0005d130(int a) {
        value = a;
        return 1;
    }
};

int main() {
    T t;
    return t.FUN_0005d130(0);
}