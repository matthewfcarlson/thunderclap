// cl-flags: /O1
struct exception {
    virtual ~exception();
};
struct X_349822 : exception {
    virtual ~X_349822() throw();
};
X_349822::~X_349822() {}
