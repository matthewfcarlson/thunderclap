// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// CSPListener::vfunc_2_adj4 @ 0x001db1f0
struct CSPListener {
    void FUN_001db200();
    void vfunc_2_adj4();
};
void CSPListener::vfunc_2_adj4() {
    ((CSPListener*)((char*)this - 4))->FUN_001db200();
}
