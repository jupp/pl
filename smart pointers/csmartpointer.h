#ifndef c_ptr_H_
#define c_ptr_H_

template <class T> class c_ptr {
  
public:
  
  explicit c_ptr(T* p = 0) : stone(0) {
    if (p) {
      stone = new tombstone(p);
    }
  }
  
  c_ptr(const c_ptr& other) {
    acquire(other.stone);
  }
  
  c_ptr& operator=(const c_ptr& other) {
    if (this != &other) {
      release();
      acquire(other.stone);
    }
    return *this;
  }
  
  ~c_ptr() {
    release();
  }
  
  T& operator*() const {
    return *(stone->ptr);
  }
  
  T* operator->() const {
    return stone->ptr;
  }
  
  T* get() {
    return stone ? stone->ptr : 0;
  }
  
  bool unique() {
    return (stone ? stone->count == 1 : true);
  }
  
private:
  
  struct tombstone {
    tombstone(T* p = 0, unsigned c = 1) : ptr(p), count(c) {}
    T* ptr;
    unsigned count;
  }* stone;
  
  void acquire(tombstone* c) {
    // increment the count
    stone = c;
    if (c) {
      ++(c -> count);
    }
  }
  
  void release() {
    // decrement the count, delete if it is 0
    if (stone) {
      if (--(stone->count) == 0) {
        delete stone->ptr;
        delete stone;
      }
      stone = 0;
    }
  }
  
};

#endif  // c_ptr_H_