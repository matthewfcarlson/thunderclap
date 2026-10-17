// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001dcf00 @ 0x001dcf00
struct Triple { unsigned int a,b,c; };
struct Wrapper {
    void FUN_001dcdf0(Triple value, unsigned int last);
    void FUN_001dcf00(Triple value, unsigned int last);
};
void Wrapper::FUN_001dcf00(Triple value, unsigned int last)
{
    FUN_001dcdf0(value, last);
}
