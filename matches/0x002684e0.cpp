namespace core {
class IRefCount {
  public:
    virtual ~IRefCount() throw();
};
IRefCount::~IRefCount() throw() {}
} // namespace core
