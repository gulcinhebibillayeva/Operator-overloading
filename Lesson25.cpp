// Lesson25.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
using namespace std;
typedef unsigned short ushort;
class Time {
private:
    unsigned short _hours=0;
    unsigned short _minutes=0;
    unsigned short _seconds=0;
public:
    Time(ushort hours, ushort minutes, ushort seconds) {
        _hours = hours;
        _minutes = minutes;
        _seconds = seconds;

    }
    Time(const Time& other) {
        _hours = other._hours;
        _minutes = other._minutes;
        _seconds = other._seconds;
    }
    // Operator Overloading
    // (++, --) (Postfix, Prefix)
    // Prefix
    Time& operator++(){
       int totalsecond = _hours * 3600 + _minutes * 60 + _seconds;
        totalsecond++;
        _hours = totalsecond / 3600;
        _minutes = (totalsecond % 3600) / 60;
        _seconds = totalsecond % 60;
        return*this;
    }
    Time& operator--(){
        int totalsecond = _hours * 3600 + _minutes * 60 + _seconds;
        totalsecond--;
        _hours = totalsecond / 3600;
        _minutes = (totalsecond % 3600) / 60;
        _seconds = totalsecond % 60;
        return*this;
    }
    Time operator++(int) {
        Time temp = *this;
        int totalsecond = _hours * 3600 + _minutes * 60 + _seconds;
        totalsecond++;
        _hours = totalsecond / 3600;
        _minutes = (totalsecond % 3600) / 60;
        _seconds = totalsecond % 60;
        return temp;
    }
    Time operator--(int) {
        Time temp = *this;
        int totalsecond = _hours * 3600 + _minutes * 60 + _seconds;
        totalsecond--;
        _hours = totalsecond / 3600;
        _minutes = (totalsecond % 3600) / 60;
        _seconds = totalsecond % 60;
        return temp;
    }

    // (<, >, <=, >=, !=, ==)
    // () => print evezi ishlesin.
    // hamisi 0-a beraber olsa => true
    bool operator!() const {
        return (_hours == 0 && _minutes == 0 && _seconds == 0);
    }
    bool operator==(const Time& other) {
        return (other._hours  == other._hours && other._minutes==other._minutes && _seconds==other._seconds);
    }
    bool operator>(const Time& other) {
        
        return (_hours * 3600 + _minutes * 60 + _seconds > other._hours * 3600 + other._minutes * 60 + other._seconds);
    }
    bool operator<(const Time& other) {
        return _hours * 3600 + _minutes * 60 + _seconds < other._hours * 3600 + other._minutes * 60 + other._seconds;
    }
    bool operator>=(const Time& other) {
        return _hours * 3600 + _minutes * 60 + _seconds >= other._hours * 3600 + other._minutes * 60 + other._seconds;
    }
    bool operator<=(const Time& other) {
        return _hours * 3600 + _minutes * 60 + _seconds <= other._hours * 3600 + other._minutes * 60 + other._seconds;
    }
    void operator ()() {
        cout << "Time" << _hours << ":" << _minutes << ":" << _seconds<<endl;
    }

};
class Vector {
private:
    int* _array = nullptr;
    size_t _size = 0;
    size_t _capacity = 15;
public:
    Vector() {
        _array = new int[_capacity];
    }
    Vector(size_t capacity) {
        _array = new int[capacity];
        _capacity = capacity;
        _size = 0;
    }

    ~Vector() {
        delete[] _array;
    }
    int* getData() const { return _array; }
    size_t size() const { return _size; }
    size_t capacity() const { return _capacity; }
    void print() const {
        for (size_t i = 0; i < _size; i++)
        {
            cout << _array[i]<<" ";
        }
        cout << endl;
    }
    int& operator[](size_t index) {
        return _array[index];
    }
    int& operator()(size_t index) {
        return _array[index];
    }

    Vector& push_back(const int value) {
        if (_size == _capacity) {
            _capacity *= 2;
            int* newarray = new int[_capacity];
            for (size_t i = 0; i < _size; i++)
            {
                newarray[i] = _array[i];
            }delete[]_array;
            _array = newarray;
        }
            _array[_size] = value;
            _size++;
            return*this;
    }
    Vector& push_front(const int value) {
        if (_size == _capacity) {
            _capacity *= 2;
            int* newarray = new int[_capacity];
            for (size_t i = 0; i < _size; i++)
            {
                newarray[i + 1] = _array[i];
            }delete[]_array;
            _array = newarray;
        }
        for (size_t i = _size; i > 0; i--) {
            _array[i] = _array[i - 1];
        }
        _array[0] = value;
        _size++;
        return *this;
    }
    Vector& pop_back() {
        if (_size > 0) {
            _size--;
        }
        return*this;
    }
    Vector& pop_front() {
        if (_size > 0) {
            for (size_t i = 0; i < _size - 1; i++)
            {
                _array[i] = _array[i + 1];
            }
            _size--;

        }
        return*this;
    }
    void delete_by_index(const size_t index) {
        if (_size < index) {
            for (size_t i = 0; i < _size - 1; i++)
            {
                _array[i] = _array[i + 1];
            }
            _size--;
        }
    }
    void insert_by_index(const size_t index, const int element) {
        if (index <= _size)
        {
            if (_size == _capacity) {
                _capacity *= 2;
                int* newarray = new int[_capacity];
                for (size_t i = 0; i < index; i++)
                {
                    newarray[i] = _array[i];

                }
                newarray[index] = element;
                for (size_t i = index; i < _size; i++)
                {
                    newarray[i + 1] = _array[i];
                }
                delete[] _array;
                _array = newarray;
                _size++;
            }
            else {
                for (size_t i = _size; i > index; i--)
                {
                    _array[i] = _array[i - 1];

                }
                _array[index] = element;
                _size++;
            }
        }
    }
    // tapsa index-ni qaytarsin,
    // tapmasa -1 (unsigned int-in max qiymeti qayidacaq)
    size_t find(const int element) {
        for (size_t i = 0; i < _size; i++)
        {
            if (_array[i] == element)
            {
                return i;
            }

        }return -1;
    }
    size_t rfind(const int element) {
        for (int i = _size; i >= 0; i--)
        {
            if (_array[i] == element)
            {
                return i;
            }
        }
        return -1;
    }
    
    // reverse true gonderilse, tersine sort olunsun.
    void sort(bool reverse = false) {
        for (size_t i = 0; i < _size - 1; i++)
        {
            for (size_t j = 0; j < _size - 1; j++)
            {
                bool condition;
                if (reverse) {
                    condition = (_array[j] < _array[j + 1]);
                }
                else
                {
                    condition = (_array[j] > _array[j + 1]);
                }
                if (condition)
                {
                    int temp = _array[j];
                    _array[j] = _array[j + 1];
                    _array[j + 1] = temp;
                }
            }

            }
        }
    };
    int main()
    {
        Time t1(12, 35, 45);
        Time t2(12, 32, 45);
        t1();
        if (t1 > t2) {
            cout << "t1 t2 den boyukdur" << endl;
        }
        if (t1 < t2) {
            cout << "t2 t1 den boyukdur" << endl;
        }
        if (t1 >= t2) {
            cout << "t1 boyukdur beraberdir t2" << endl;
        }
        if (t1 <= t2) {
            cout << "t1 kicikdir beraberdir t2" << endl;
        }
        if (!t1) {
            cout << "t1 00:00:00" << endl;
        }
        Vector v;
        v.push_back(10);
        v.push_back(50);
        v.push_back(30);
        v.push_back(40);
        v.push_back(60);
        cout << "orjinal"<<endl;
        v.print();
        cout << "Artan sira ile"<<endl;
        v.sort();
        v.print();
        cout << "azalan sira ile"<<endl;
        v.sort(true);
        v.print();
        cout << "Sonuncu  sil"<<endl;
        v.pop_back();
        v.print();
        cout << "evvelden sil"<<endl;
        v.pop_front();
        v.print();
        cout << "ikinci indeksi sil" << endl;
        v.delete_by_index(2);
        v.print();
        cout << "3 cu indekse 12 elave et" << endl;
        v.insert_by_index(3,12);
        v.print();

        return 0;
    }