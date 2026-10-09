class Context {
public:
    int* Lookup(int);
};
class Obj {
public:
    char pad[0x0c];
    Context* mContext;
    int Target(int);
};
int Obj::Target(int arg)
{
    int* p = mContext->Lookup(arg);
    if (p)
        return (int)p + 0x30;
    return 0;
}