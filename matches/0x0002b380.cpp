struct Args {
    int x, y, z;
};
struct Obj {
    void FUN_00028400(int, Args);
    void FUN_0002b380(int a, int b, int c);
};
void Obj::FUN_0002b380(int a, int b, int c) {
    volatile Args args;
    args.x = b;
    args.z = c;
    args.y = 0;
    FUN_00028400(a, *(Args*)&args);
}