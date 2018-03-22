template<typename T>
T* allocate(std::size_t n) {
  auto p = std::malloc(n*sizeof(T));
  if (!p)
    throw std::bad_alloc();
  return reinterpret_cast<T *>(p);
}

template<typename T>
void deallocate(T* p,std::size_t n) {
  std::free(p);
}

template<typename U, typename ...Args>
void constuct(U* p, Args&& ...args) {
  new(p) U(std::forward(args)...);
}

template<typename T>
void destroy(T* p) {
  p->~T();
}