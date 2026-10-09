class Action { char pad[0x1c]; };
class NonCopyable {};
class IRefCount {};
class PrintAction : public Action, public NonCopyable, public IRefCount {
public:
    char pad[4];
    int mText;
    int mFormat;
    int mArg;
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool vfunc_3(int, int);
};
extern int FUN_00238bb0(int, int, const char *, int);
const char formatString[] = "%s\n";
bool PrintAction::vfunc_3(int a, int b) {
    int p = *(int*)((char*)this + 0x1c);
    if (*(int*)((char*)p + 0x14))
        FUN_00238bb0(*(int*)((char*)this + 0x20), *(int*)((char*)p + 0x10), formatString, *(int*)((char*)p + 0x14));
    return false;
}