#ifndef s_ptr_H_
#define s_ptr_H_

template <class T> class s_ptr {
  
public:
  
  explicit s_ptr(T* ptr = 0) : ptr_(ptr) {}
  
  s_ptr& operator=(s_ptr& other) {
    if (this != &other) {
      delete ptr_;
      ptr_ = other.ptr_;
      other.ptr_ = 0;
    }
    return *this;
  }
  
  ~s_ptr() {
    delete ptr_;
  }
  
  T& operator*() const {
    return *ptr_;
  }
  
  T* operator->() const {
    return ptr_;
  }
  
private:
  
  T* ptr_;
  
};

#endif  // s_ptr_H_