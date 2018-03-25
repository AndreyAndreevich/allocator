  template<typename T>
  struct element {
    element* next = nullptr;
    T data;
  };

template<
  typename T,
  class Allocator = std::allocator<element<T>>
> class my_container {
  Allocator alloc;
  size_t count = 0;
  element<T>* front_el = nullptr;
  element<T>* end_el = nullptr;

public:
  ~my_container() {
    while (front_el->next) {
      auto p = front_el->next->next;
      alloc.deallocate(front_el->next,1);
      front_el->next = p;
    }
    alloc.deallocate(front_el,1);
  }

  void push(T data) {
    if (count) {
      end_el->next = alloc.allocate(1);
      alloc.construct(end_el->next, *end_el->next);
      end_el = end_el->next;
      end_el->data = data;
    } else {
      front_el = alloc.allocate(1);
      alloc.construct(front_el, *front_el);
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

  element<T>* begin() {
    return front_el;
  }

  element<T>* end() {
    return end_el+1;
  }

  size_t size() {
    return count;
  }
/*
  void pop() {
    auto p = front_el;
    //std::cout << p << " " << p->data << std::endl;
    if (count > 1) {
      front_el = front_el->next;
      alloc.destroy(p);
      alloc.deallocate(p,1);
      count--;
    } 
    else if (count == 1) 
    {
      front_el = nullptr;
      end_el = nullptr;
      std::cout << 555555 << std::endl; 
      alloc.destroy(p);
      alloc.deallocate(p,1);
      count--;
    }
  }
  */

};