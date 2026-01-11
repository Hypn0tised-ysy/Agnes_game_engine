#pragma once
#include "IRuntimeModule.hpp"

namespace My {
class GraphicsManager : public IRuntimeModule {
public:
  virtual ~GraphicsManager() override {}

  virtual int Initialize() override;
  virtual void Finalize()override;

  virtual void Tick()override;
};
} // namespace My
