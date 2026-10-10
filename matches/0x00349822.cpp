// cl-flags: /O1
struct exception {
    virtual ~exception();
};
struct X : exception {
    virtual ~X() throw();
};
X::~X() {}
