struct Handler {
    void FUN_0026e140(void* data, int size);
    void FUN_0026e500(int value);
};
void Handler::FUN_0026e500(int value) {
    int args[2];
    args[0] = 3;
    args[1] = value;
    FUN_0026e140(args, 8);
}