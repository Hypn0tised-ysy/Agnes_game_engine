#pragma once
#include "GfxConfiguration.h"
#include "IRuntimeModule.hpp"
#include "Interface.hpp"

namespace My {
class IApplication : public IRuntimeModule {
public:
  virtual int Initialize() override = 0;
  virtual void Finalize() override = 0;

  virtual void Tick() override = 0;

  virtual bool IsQuit()  = 0;

  virtual GfxConfiguration& GetGfxConfiguration() = 0;
};
} // namespace My
