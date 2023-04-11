#include <iostream>
#include <memory>
#include <algorithm>

using namespace std;

template <typename T>
class Sorted {
public:
    Sorted() : size_{ 0 }, capacity_{ 10 }, data_{ make_unique<T[]>(capacity_) } {}

    void add(T& elem) {
        if (size_ == capacity_) {
            reserve(capacity_ * 2);
        }
        auto it = lower_bound(data_.get(), data_.get() + size_, elem);
        copy_backward(it, data_.get() + size_, data_.get() + size_ + 1);
        *it = elem;
        ++size_;
    }

    void remove(T& elem) {
        auto it = lower_bound(data_.get(), data_.get() + size_, elem);
        if (it != data_.get() + size_ && *it == elem) {
            copy(it + 1, data_.get() + size_, it);
            --size_;
        }
    }

    void print() const {
        for (int i = 0; i < size_; ++i) {
            cout << data_[i] << "\n";
        }
    }

private:
    void reserve(int new_capacity) {
        auto new_data = make_unique<T[]>(new_capacity);
        copy(data_.get(), data_.get() + size_, new_data.get());
        capacity_ = new_capacity;
        data_ = move(new_data);
    }

    int size_;
    int capacity_;
    unique_ptr<T[]> data_;
};

main() {
    return 0;
}
