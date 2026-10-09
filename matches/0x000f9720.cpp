class Stack {
    char pad[0x10];

  public:
    int count;
    int Pop();
};
int Stack::Pop() {
    int n = count;
    if (n <= 0)
        return 0;
    int v = ((int*)this)[n];
    count = n - 1;
    return v;
}