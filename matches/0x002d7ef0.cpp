int Target(int a, int b) {
    if (a && b)
        return *(int*)(b + 4);
    return 0;
}