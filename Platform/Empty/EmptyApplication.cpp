#include "BaseApplication.hpp"
#include "GfxConfiguration.h"
#include "GraphicsManager.hpp"
#include "IApplication.hpp"
#include "MemoryManager.hpp"
#include <memory>

namespace My {
/*
为什么要如此大费周章地用函数来返回静态变量的引用呢？
控制变量的初始化顺序
cpp不保证不同翻译单元中的静态变量初始化顺序
使用函数内的静态变量可以保证在第一次调用函数时才初始化该变量，从而避免了初始化顺序的问题
*/
std::unique_ptr<IApplication> &getEmptyApp() {
  static GfxConfiguration config;
  static std::unique_ptr<IApplication> g_pApp =
      std::make_unique<BaseApplication>(config);
  return g_pApp;
}

std::unique_ptr<MemoryManager> &getMemoryManager() {
  static std::unique_ptr<MemoryManager> g_pMemoryManager =
      std::make_unique<MemoryManager>();
  return g_pMemoryManager;
}

std::unique_ptr<GraphicsManager> &getGraphicsManager() {

  static std::unique_ptr<GraphicsManager> g_pGraphicsManager =
      std::make_unique<GraphicsManager>();
  return g_pGraphicsManager;
}

} // namespace My
