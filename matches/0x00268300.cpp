class IRefCount {
  public:
    virtual void AddRef();
    virtual void Release();
    virtual ~IRefCount();
};

IRefCount::~IRefCount() {}
