// Same code shape as 0x002b87d0 (propagated; names are from that function)
int FUN_002b8800(int x) {
    if (x != 0x48544f42) {
        if (x != 0x54524556) {
            return (x == 0x545a5248) ? 2 : 0;
        }
        return 1;
    }
    return 3;
}