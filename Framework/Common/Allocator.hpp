#include <cstdint>
namespace My {
// 很像xv6的run
// 一个page会包含若干个block
// Allocator负责向OS申请若干页，将页划分成block用于分配
struct BlockHeader {
  BlockHeader *pNext;
};

struct PageHeader {
  PageHeader *pNext;
  BlockHeader *Blocks() { return reinterpret_cast<BlockHeader *>(this + 1); }
};

class Allocator {
public:
//将一个block的数据部分填入alloc或者free字段，剩下的用于对齐的部分填入align字段
  static const uint8_t PATTERN_ALIGN = 0xFC;
  static const uint8_t PATTERN_ALLOC = 0xFD;
  static const uint8_t PATTERN_FREE = 0xFE;

  Allocator();
  Allocator(size_t data_size, size_t page_size, size_t alignment);
  ~Allocator();

  void Reset(size_t data_size, size_t page_size, size_t alignment);

  // 分配与释放blocks
  void *Alloc();
  void Free(void *ptr);
  void FreeAll();

private:
  BlockHeader *getNextBlock(BlockHeader *pBlock);

  // page list
  PageHeader *m_pPageList;

  // free block list
  BlockHeader *m_pFreeList;

  size_t m_szDataSize;
  size_t m_szPageSize;
  size_t m_szAlignmentSize;
  size_t m_szBlockSize;
  size_t m_nBlocksPerPage;

  size_t m_nPages;
  size_t m_nBlocks;
  size_t m_nFreeBlocks;

  // disable copy & assignment
  // 浅拷贝 打咩de su
  Allocator(const Allocator &) = delete;
  Allocator &operator=(const Allocator &) = delete;

// Debug
#if defined(_DEBUG)
  // fill a free page with debug patterns
  void FillFreePage(PageHeader *pPage);

  // fill a block with debug patterns
  void FillFreeBlock(BlockHeader *pBlock);

  // fill an allocated block with debug patterns
  void FillAllocatedBlock(BlockHeader *pBlock);
#endif
};

} // namespace My
