#ifndef NONREPEATLIST
#define NONREPEATLIST
#include <assert.h>

template <class T>

class NoRepeatList
{
 private:
    int m_length;
    T *m_data;
    bool checkCoincidence(const T &value);

public:
    NoRepeatList();

    NoRepeatList(int length);

    NoRepeatList(const NoRepeatList &anotherList);

    NoRepeatList(T *data, int length);

    ~NoRepeatList();

    NoRepeatList& operator=(const NoRepeatList &anotherList);

    int size() const;

    void append(const NoRepeatList &appendedList);

    void append(const T &value);

    void clear();

    void removeAt(int i);

    void removeValue(const T &value);

    const T& at(int i);

    int indexOf(const T &value);

    void setAt(int i, const T &value);

    void insert(int i, const T &value);

};

#include "nonrepeatlist.inl"

#endif // NONREPEATLISTT

