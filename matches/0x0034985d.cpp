// cl-flags: /O1
struct exception {
    virtual ~exception();
};
struct X_34985d : exception {
    virtual ~X_34985d() throw();
};
X_34985d::~X_34985d() {}
