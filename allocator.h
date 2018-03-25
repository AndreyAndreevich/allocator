template<typename T>
class my_allocator {
  size_t N = 10;
  size_t count = 0;
  T* p;
public:
  using value_type = T;

  using pointer = T*;
  using const_pointer = const T*;
  using reference = T&;
  using const_reference = const T&;

  template<typename U>
  struct rebind {
    using other = my_allocator<U>;
  };

  T* allocate(std::size_t n) {
    if (count++%N) {
      p++;
    }
    else {
      p = reinterpret_cast<T *>(std::malloc(N*n*sizeof(T)));
       if (!p)
        throw std::bad_alloc();
    }
    return p;
  }

  void deallocate(T* p,std::size_t n) {
    if (!count) {
      return;
    }
    if (!(--count%N)) {
      std::free(p); 
    }
  }

  template<typename U, typename ... Args>
  void construct(U *p, Args&& ... args) {
    new(p) U(std::forward<Args>(args)...);
  }

  void destroy(T* p) {
    p->~T();
  }
};