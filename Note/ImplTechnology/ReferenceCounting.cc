/*
  Reference Counting
  This technology can allow multiple objects to share the same real value.
  The right time for using this technology:
    1)  Relatively large numbers of objects 
        share a relatively small number of real values
    2)  The cost to construct or destroy an object is high,
        or they use a lot of memory
*/

// base class
// To do the reference-counting things
class RCObject
{
public:
    void addReference() { ++refCount; }
    void removeReference() { if (--refCount == 0) delete this; }
    void markUnshareable() { shareable = false; }
    bool isShareable() const { return shareable; }
    bool isShared() const { return refCount > 1; }

protected:
    RCObject() :refCount(0), shareable(true) {}
    RCObject(const RCObject& rhs) :refCount(0), shareable(true) {}
    RCObject& operator=(const RCObject& rhs) { return *this; }
    virtual ~RCObject() = 0 {}

private:
    int refCount;
    bool shareable;
};

// (Indirectly) points to a object that need reference-counting
template <class T>
class RCPtr
{
public:
    RCPtr(T *ptr = 0) :counter(new CountHolder)
    {
        counter->p = ptr;
        init();
    }
    RCPtr(const RCPtr& rhs) :counter(rhs.counter)
    {
        init();
    }
    ~RCPtr() { counter->removeReference(); }
    RCPtr& operator=(const RCPtr& rhs)
    {
        if (counter != rhs.counter)
        {
            counter->removeReference();
            counter = rhs.counter;
            init();
        }
        return *this;
    }

    const T* operator->() const { return counter->p; }
    T* operator->() { makeCopy(); return counter->p; }
    const T& operator*() const { return *(counter->p); }
    T& operator*() { makeCopy(); return *(counter->p); }

private:
    // The pointer inside the CountHolder points to a real object
    struct CountHolder : public RCObject
    {
        ~CountHolder() { delete p; }
        T *p;
    };
    CountHolder *counter;

    void init()
    {
        if (!counter->isShareable())
        {
            T *oldValue = counter->p;
            counter = new CountHolder;
            counter->p = new T(*oldValue);
        }
        counter->addReference();
    }

    void makeCopy()
    {
        if (counter->isShared())
        {
            T *oldValue = counter->p;
            counter->removeReference();
            counter = new CountHolder;
            counter->p = new T(*oldValue);
            counter->addReference();
        }
    }
};

// Here is an example
// If we have a class named Widget like this:
class Widget
{
public:
    Widget(int size);
    Widget(const Widget& rhs);
    ~Widget();
    Widget& operator=(const Widget& rhs);
    void doSth();
    int show() const;
};

// If it need reference-counting,
// we might define a class named RCWidget like this:
class RCWidget
{
public:
    RCWidget(int size) :value(new Widget(size)) {}
    void doSth() { value->doSth(); }
    int show() const { return value->show(); }
private:
    RCPtr<Widget> value;
};
