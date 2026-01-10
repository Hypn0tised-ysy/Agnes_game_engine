#pragma once
#include "GfxConfiguration.h"
#include "IApplication.hpp"

namespace My {
Interface BaseApplication : implements IApplication {
public:
  BaseApplication(GfxConfiguration & config); //
  virtual int Initialize() override;
  virtual void Finalize() override;

  virtual void Tick() override;

  virtual bool IsQuit() override;

public:
protected:
  static bool m_bQuit; // m stands for member while b stands for boolean
  GfxConfiguration m_Config;

private:
  BaseApplication(){}; // hide constructor to force user to provide
                       // configuration
};
} // namespace My
