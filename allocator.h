template<typename T>
class my_allocator {
  const size_t N = 10;
  size_t cout = 0;
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
    std::cout << __PRETTY_FUNCTION__ << "[n = " << n << "]" << std::endl;
    if (cout++%N) {
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
    std::cout << __PRETTY_FUNCTION__ << "[n = " << n << "]" << std::endl;
    if (!(--cout%N))
      std::free(p); 
  }

  template<typename U, typename ... Args>
  void construct(U *p, Args&& ... args) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    new(p) U(std::forward<Args>(args)...);
  }

  void destroy(T* p) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    p->~T();
  }

};