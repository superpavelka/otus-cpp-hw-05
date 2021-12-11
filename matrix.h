#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <tuple>

template<typename T, T default_value, int dim = 2>
class Matrix
{
private:

    class ProxyMatrix
    {
        friend class Matrix;
    public:

        ProxyMatrix operator[](int idx)
        {
            return ProxyMatrix(*this, idx);
        }

        T& operator=(const T& value)
        {
            if (value != _default_value)
            {
                _parent._matrix[_index] = value;
                return _parent._matrix[_index];
            }
            else 
                return _default_value;
        }

        bool operator==(const T& value)
        {
            return find() == value;
        }

        friend std::ostream& operator<<(std::ostream& os, const ProxyMatrix& m)
        {
            os << m.find();
            return os;
        }

    private:
        ProxyMatrix(Matrix& parent, int index)
            : _parent(parent)
            , _index({ index })
            , _default_value(default_value)
        {}

        ProxyMatrix(const ProxyMatrix& other, int index)
            : _parent(other._parent)
            , _index(other._index)
            , _default_value(default_value)
        {
            _index.push_back(index);
        }

        T find() const
        {
            T tmp = _default_value;
            auto it = _parent._matrix.find(_index);
            auto end = _parent._matrix.end();
            if (it != end) 
                tmp = _parent._matrix[_index];
            return tmp;
        }

        Matrix& _parent;
        std::vector<int> _index;
        T _default_value;

    };

    std::map<std::vector<int>, T> _matrix;

public:

    using matrix_iterator = typename std::map<std::vector<int>, T>::iterator;

    class Iterator 
    {
    public:
        Iterator() : _it(matrix_iterator(nullptr)) {}

        Iterator(matrix_iterator it) : _it(it) {}

        bool operator==(const Iterator& other) const
        {
            return _it == other._it;
        }

        bool operator!=(const Iterator& other) const
        {
            return !(*this == other);
        }

        std::tuple<int, int, T> operator*() const
        {
            return std::make_tuple((*_it).first.at(0), (*_it).first.at(1), (*_it).second);
        }

        Iterator& operator++()
        {
            ++_it;
            return *this;
        }

    private:
        matrix_iterator _it;
    };

    Matrix() = default;

    ProxyMatrix operator[](int row)
    {
        return ProxyMatrix(*this, { row });
    }

    std::size_t size() const
    {
        return _matrix.size();
    }

    Iterator begin()
    {
        return Iterator(_matrix.begin());
    }

    Iterator end()
    {
        return Iterator(_matrix.end());
    }
};