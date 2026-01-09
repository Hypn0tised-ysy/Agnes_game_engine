#pragma once
#include "IApplication.hpp"

namespace My {
Interface BaseApplication : implements IApplication {
public:
  virtual int Initialize() override;
  virtual void Finalize() override;

  virtual void Tick() override;

  virtual bool IsQuit() override;

protected:
  bool m_bQuit; // m stands for member while b stands for boolean
};
} // namespace My
