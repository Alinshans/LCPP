/*
  Use variadic template to simulate a tuple
*/
#ifndef TUPLE_H_
#define TUPLE_H_

template<typename ...TArgs>    class Tuple;

template<typename T, typename ...TArgs>
class Tuple<T, TArgs...> : public Tuple<TArgs...>
{
public:
    T value;
    Tuple<TArgs...>    TupleList;

    Tuple()
    {
    }

    Tuple(const T& v, const TArgs& ...args)
        :TupleList(args...), value(v)
    {
    }


    static int Compare(const Tuple& lhs, const Tuple& rhs)
    {
        if (lhs.value < rhs.value)
        {
            return -1;
        }
        else if (lhs.value > rhs.value)
        {
            return 1;
        }
        return lhs.TupleList.Compare(lhs.TupleList, rhs.TupleList);
    }

    bool operator==(const Tuple& value)const { return Compare(*this, value) == 0; }
    bool operator!=(const Tuple& value)const { return Compare(*this, value) != 0; }
    bool operator< (const Tuple& value)const { return Compare(*this, value) < 0; }
    bool operator<=(const Tuple& value)const { return Compare(*this, value) <= 0; }
    bool operator> (const Tuple& value)const { return Compare(*this, value) > 0; }
    bool operator>=(const Tuple& value)const { return Compare(*this, value) >= 0; }
};

template<>
class Tuple<>
{
public:
    static int Compare(const Tuple& lhs, const Tuple& rhs)
    {
        return 0;
    }
};

#endif // !TUPLE_H_
