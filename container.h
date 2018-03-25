template<typename T>
class my_container {
  size_t* count = nullptr;
  my_container* next_el = nullptr;
  my_container* end_el = nullptr;
  T data;
public:
  my_container() {
    if (count)
      (*count)++;
    else 
      count = new size_t(0);
  }
  void push(T data) {
    if (!count) {
      count = new size_t(0);
    }
    if (*count) {
      end_el->next_el = new my_container();
      end_el = end_el->next_el;
      end_el->data = data;
    } else {
      this->data = data;
      end_el = this;
    }
    (*count)++;
  }

  T front() {
    if (count)
      return this->data;
  }

  T back() {
    if (count)
      return end_el->data;
  }

  void pop() {
    if (!count)
      return;
    if (*count > 1) {
      (*count)--;
      std::swap(data,next_el->data);
      std::swap(next_el,next_el->next_el);
      delete next_el;
      if (*count == 1) {
        end_el = this;
        next_el = nullptr;
      }
    } else {
      next_el = nullptr;
      end_el = nullptr;
      delete count;
      count = nullptr;
    }
  }
};