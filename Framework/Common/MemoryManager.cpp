#include "MemoryManager.hpp"
#include <cstddef>
#include <cstdlib>

using namespace My;

namespace My {
// k前缀表示constant
// m表示member
// s表示static
static const uint32_t kBlockSizes[] = {
    // 4-increments
    4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 64, 68, 72, 76,
    80, 84, 88, 92, 96,

    // 32-increments
    128, 160, 192, 224, 256, 288, 320, 352, 384, 416, 448, 480, 512, 544, 576,
    608, 640,

    // 64-increments
    704, 768, 832, 896, 960, 1024};

static const uint32_t kPageSize = 8192;
static const uint32_t kAlignment = 4;

// number of elements in the block size array
static const uint32_t kNumBlockSizes =
    sizeof(kBlockSizes) / sizeof(kBlockSizes[0]);

// largest valid block size
static const uint32_t kMaxBlockSize = kBlockSizes[kNumBlockSizes - 1];

    size_t*        MemoryManager::m_pBlockSizeLookup;
    Allocator*     MemoryManager::m_pAllocators;
} // namespace My

int My::MemoryManager::Initialize() {
  static bool s_bInitialized = false;
  if (!s_bInitialized) {
    m_pBlockSizeLookup = new size_t[kMaxBlockSize + 1];
    m_pAllocators = new Allocator[kNumBlockSizes];

    // initialize block size lookup table
    size_t current_index = 0;
    for (size_t size = 1; size <= kMaxBlockSize; size++) {
      if (size > kBlockSizes[current_index]) {
        ++current_index;
      }
      m_pBlockSizeLookup[size] = current_index;
    }

    // initialize allocators
    for (size_t i = 0; i < kNumBlockSizes; i++) {
      m_pAllocators[i].Reset(kBlockSizes[i], kPageSize, kAlignment);
    }
  }
  s_bInitialized = true;
  return 0;
}
void My::MemoryManager::Finalize() {
  delete[] m_pBlockSizeLookup;
  delete[] m_pAllocators;
}

void My::MemoryManager::Tick() {}
void *My::MemoryManager::Allocate(size_t size) {
  Allocator *pAlloc = LookUpAllocator(size);
  if (pAlloc)
    return pAlloc->Alloc();
  else
    return malloc(size);
}
void My::MemoryManager::Free(void *ptr, size_t size) {
  Allocator *pAlloc = LookUpAllocator(size);
  if (pAlloc)
    pAlloc->Free(ptr);
  else
    free(ptr);
}
Allocator *My::MemoryManager::LookUpAllocator(size_t size) {
  if (size <= kMaxBlockSize) {
    size_t index = m_pBlockSizeLookup[size];
    return &m_pAllocators[index];
  } else
    return nullptr;
}
