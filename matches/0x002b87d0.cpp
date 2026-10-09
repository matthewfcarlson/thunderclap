int FUN_002b87d0(int x) {
    if (x != 0x48544f42) {
        if (x != 0x54524556) {
            return (x == 0x545a5248) ? 2 : 0;
        }
        return 1;
    }
    return 3;
}