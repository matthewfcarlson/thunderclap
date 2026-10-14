// cl-flags: /O1
struct exception {
    virtual ~exception();
};
struct X_349895 : exception {
    virtual ~X_349895() throw();
};
X_349895::~X_349895() {}
