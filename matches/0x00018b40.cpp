namespace core
{
class IRefCount
{
public:
    virtual void vfunc_0();
    virtual void Release();
    virtual ~IRefCount();
    int mRefCount;
};

void IRefCount::Release()
{
    if (--mRefCount < 1)
        delete this;
}
}

namespace pure3d
{
class NonCopyable : public core::IRefCount
{
};
}
