template<typename T>
class my_iterator {
public:
    my_iterator(T *first) {
        current = first;
    }

    T &operator+(int n) {
        for(int i = 0; i < n; i++)
            current = current->next;
        return *current;
    }

    T &operator++(int) {
      current = current->next;
      return *current;
    }

    T &operator++() {
      current = current->next;
      return *current;
    }

    bool operator==(const my_iterator &it) {
        return current == it.current;
    }

    bool operator!=(const my_iterator &it) {
        return current != it.current;
    }
    
    T &operator*() {
        return *current;
    }
private:
    T *current;
};