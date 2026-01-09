#pragma once
#include "IRuntimeModule.hpp"
#include "Interface.hpp"

namespace My {
Interface IApplication : implements IRuntimeModule {
public:
  virtual int Initialize() override = 0;
  virtual void Finalize() override = 0;

  virtual void Tick() override = 0;

  virtual bool IsQuit()  = 0;
};
} // namespace My
