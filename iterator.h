namespace my {

template<typename T>
class iterator : public std::iterator<std::input_iterator_tag,T> {
public:
    iterator(T *first) {
        current = first;
    }

    iterator &operator++() {
      current = current->next;
      return *this;
    }

    bool operator!=(const iterator &it) {
        return current != it.current;
    }
    
    T &operator*() {
        return *current;
    }
private:
    T *current;
};

}