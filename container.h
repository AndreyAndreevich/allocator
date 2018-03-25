template<typename T>
class my_container {

  struct element {
    element* next = nullptr;
    T data;
  };

  size_t count = 0;
  element* front_el = nullptr;
  element* end_el = nullptr;

public:

  void push(T data) {
    if (count) {
      end_el->next = new element;
      end_el = end_el->next;
      end_el->data = data;
    } else {
      front_el = new element;
      front_el->data = data;
      end_el = front_el;
    }
    count++;
  }

  T front() {
    if (count)
      return front_el->data;
  }

  T back() {
    if (count)
      return end_el->data;
  }

  void pop() {
    auto p = front_el;
    if (count > 1) {
      front_el = front_el->next;
      delete p;
      count--;
    } 
    else if (count) 
    {
      front_el = nullptr;
      end_el = nullptr;
      delete p;
      count--;
    }
  }
};