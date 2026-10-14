// cl-flags: /O1
struct exception {
    virtual ~exception();
};
struct X_349879 : exception {
    virtual ~X_349879() throw();
};
X_349879::~X_349879() {}
