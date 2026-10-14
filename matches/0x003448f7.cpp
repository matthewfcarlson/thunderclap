// cl-flags: /O1
struct exception {
    virtual ~exception();
};
struct X_3448f7 : exception {
    virtual ~X_3448f7() throw();
};
X_3448f7::~X_3448f7() {}
