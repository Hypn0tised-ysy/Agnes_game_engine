#pragma once
#include "Allocator.hpp"
#include "IRuntimeModule.hpp"
#include <cstddef>
#include <utility>

namespace My {
class MemoryManager : implements IRuntimeModule {
public:
  template <typename T, typename... Arguments> T *New(Arguments... parameters) {
    return new (Allocator(sizeof(T))) T(std::forward<Arguments>(parameters)...);
  }

  template <typename T> void Delete(T *ptr) {
    if (ptr) {
      reinterpret_cast<T *>(ptr)->~T();
      Free(ptr, sizeof(T));
    }
  }

  virtual ~MemoryManager() override {}

  virtual int Initialize() override;
  virtual void Finalize() override;

  virtual void Tick() override;

  void *Allocate(size_t size);
  void Free(void *ptr, size_t size);

private:
  // 比如我们想知道size为21byte的内存块应该找哪个allocator来分配，查m_pBlockSizeLookup[21]取得index，m_pAllocators[index]就是所需的allocator
  // 对应的allocator分配的block为能容纳21byte的最小的block->也就是24byte
  static size_t *m_pBlockSizeLookup;
  static Allocator *m_pAllocators;

private:
  static Allocator *LookUpAllocator(size_t size);
};
} // namespace My
