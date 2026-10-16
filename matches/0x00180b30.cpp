class Base {
  public:
    virtual ~Base() throw();
};
class CSMPropIsCharacterCondition : public Base {
  public:
    virtual ~CSMPropIsCharacterCondition() throw();
};
CSMPropIsCharacterCondition::~CSMPropIsCharacterCondition() throw() {}