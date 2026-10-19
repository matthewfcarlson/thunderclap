// Same code shape as 0x00066860 (propagated; names are from that function)
struct ThisCall_00230b60 {
    void FUN_00230b60();
};
struct Target_1ad4b0 {
    Target_1ad4b0* Run(int);
};
Target_1ad4b0* Target_1ad4b0::Run(int x) {
    ((ThisCall_00230b60*)(this))->FUN_00230b60();
    return this;
}