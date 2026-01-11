#include "GraphicsManager.hpp"
#include "IApplication.hpp"
#include "MemoryManager.hpp"
#include <stdio.h>
#include <memory>

namespace My {
std::unique_ptr<IApplication>&    getEmptyApp();
std::unique_ptr<MemoryManager>&   getMemoryManager();
std::unique_ptr<GraphicsManager>& getGraphicsManager();
} // namespace My

int main() {
  int ret = 0;

  // 取引用，避免重复调用 getter
  auto& app = My::getEmptyApp();
  auto& memoryManager = My::getMemoryManager();
  auto& graphicsManager = My::getGraphicsManager();

  if (!app || !memoryManager || !graphicsManager) {
    printf("Fatal: global systems not created.\n");
    return -1;
  }

  if ((ret = app->Initialize()) != 0) {
    printf("Application Initialize failed with error code %d\n", ret);
    return ret;
  }

  if ((ret = memoryManager->Initialize()) != 0) {
    printf("MemoryManager Initialize failed with error code %d\n", ret);
    return ret;
  }

  if ((ret = graphicsManager->Initialize()) != 0) {
    printf("GraphicsManager Initialize failed with error code %d\n", ret);
    return ret;
  }

  while (!app->IsQuit()) {
    app->Tick();
    memoryManager->Tick();
    graphicsManager->Tick();
  }

  graphicsManager->Finalize();
  memoryManager->Finalize();
  app->Finalize();

  return 0;
}
