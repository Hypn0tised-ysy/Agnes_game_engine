#pragma once
#include "IApplication.hpp"

namespace My {
Interface BaseApplication : implements IApplication {
public:
  virtual int Initialize() ;
  virtual void Finalize() ;

  virtual void Tick() ;

  virtual bool IsQuit() ;

  protected: 
  bool m_bQuit;//m stands for member while b stands for boolean
};
} // namespace My