struct ThisCall_00230b60 {
    void FUN_00230b60();
};
struct Target_66860 {
    Target_66860* Run(int);
};
Target_66860* Target_66860::Run(int x) {
    ((ThisCall_00230b60*)(this))->FUN_00230b60();
    return this;
}