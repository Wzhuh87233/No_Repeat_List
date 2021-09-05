#include "nonrepeatlist.h"

template <class T>
bool NoRepeatList<T>::checkCoincidence(const T &value)
{
    for (int i = 0; i < m_length; ++i)
        if (m_data[i] == value) return false;
    return true;
}

template <class T>
NoRepeatList<T>::NoRepeatList()
{
    m_length = 0;
    m_data = nullptr;
}

template <class T>
NoRepeatList<T>::NoRepeatList(int length)
{
   assert(length > 0);
   m_data = new T[length];
   m_length = length;
}

template <class T>
NoRepeatList<T>::NoRepeatList(const NoRepeatList &anotherList)
{
      m_length = anotherList.m_length;
      if (anotherList.m_data != nullptr)
      {
          m_data = new T[m_length];
          for (int i = 0; i < m_length; ++i)
              m_data[i] = anotherList.m_data[i];
      }
      else m_data = nullptr;
}

template <class T>
NoRepeatList<T>::NoRepeatList(T *data, int length)
{
   m_length = length;
   m_data = new T[length];
   for (int i = 0; i < length; ++i)
   {
      m_data[i] = data[i];
   }
}

template <class T>
NoRepeatList<T>::~NoRepeatList()
{
   delete [] m_data;
}

template <class T>
NoRepeatList<T>& NoRepeatList<T>::operator=(const NoRepeatList &anotherList)
{
    if (this == &anotherList)
        return *this;

    delete [] m_data;

    m_length = anotherList.m_length;

    if (anotherList.m_data != nullptr)
    {
        m_data = new T[m_length];
        for (int i = 0; i < m_length; ++i)
            m_data[i] = anotherList.m_data[i];
    }
    else m_data = nullptr;

    return *this;
}

template <class T>
int NoRepeatList<T>::size() const
{
    return m_length;
}

template <class T>
void NoRepeatList<T>::append(const NoRepeatList &appendedList)
{
   T *data = new T[m_length + appendedList.m_length];
   for (int i = 0; i < m_length; ++i)
   {
     data[i] = m_data[i];
   }
   for (int i = 0; i < appendedList.m_length; ++i)
   {
       data[m_length + i] = appendedList.m_data[i];
   }
   m_length = m_length + appendedList.m_length;
   delete [] m_data;
   m_data = data;
}

template <class T>
void NoRepeatList<T>::append(const T &value)
{
  if (!checkCoincidence(value))
      return;
  T *data = new T[m_length + 1];
  for (int i = 0; i < m_length; ++i)
  {
      data[i] = m_data[i];
  }
  data[m_length] = value;
  delete [] m_data;
  m_data = data;
  ++m_length;
}

template <class T>
void NoRepeatList<T>::clear()
{
  delete [] m_data;
  m_data = nullptr;
  m_length = 0;
}

template <class T>
void NoRepeatList<T>::removeAt(int i)
{
  assert(i >= 0 && i < m_length);

  if (m_length == 1)
      clear();

  T *data = new T[m_length - 1];
  int k = 0;
  for (int j = 0; j < m_length; ++j)
  {
      if (i == j)
      {
          continue;
      }
      data[k] = m_data[j];
      ++k;
  }
  delete [] m_data;
  m_data = data;
  --m_length;
}

template <class T>
void NoRepeatList<T>::removeValue(const T &value)
{
  if (!checkCoincidence(value))
  {
      T *data = new T[m_length - 1];
      int j = 0;
      for (int i = 0; i < m_length - 1; ++i)
      {
        if (m_data[j] == value)
        {
            ++j;
            --i;
            continue;
        }
        data[i] = m_data[j];
        ++j;
      }
      delete [] m_data;
      m_data = data;
      --m_length;
  }
}

template <class T>
const T& NoRepeatList<T>::at(int i)
{
  assert(i >= 0 && i < m_length);
  return m_data[i];
}

template <class T>
int NoRepeatList<T>::indexOf(const T &value)
{
  for (int i = 0; i < m_length; ++i)
  {
      if (m_data[i] == value)
          return i;
  }
  return -1;
}

template <class T>
void NoRepeatList<T>::setAt(int i, const T &value)
{
    assert(i >= 0 && i < m_length);
    if (!checkCoincidence(value))
        return;
    m_data[i] = value;
}

template <class T>
void NoRepeatList<T>::insert(int i, const T &value)
{
    assert(i >= 0 && i < m_length);
    if (!checkCoincidence(value))
        return;
    T *data = new T[m_length + 1];
    int k = 0;
    for (int j = 0; j < m_length + 1; ++j)
    {
        if (j == i)
        {
            data[j] = value;
            continue;

        }
        data[j] = m_data[k];
        ++k;
    }
    delete [] m_data;
    m_data = data;
    ++m_length;
}

