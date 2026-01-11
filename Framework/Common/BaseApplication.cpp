#include "BaseApplication.hpp"
#include <iostream>

bool My::BaseApplication::m_bQuit = false;

My::BaseApplication::BaseApplication(GfxConfiguration &config)
    : m_Config(config) {}

int My::BaseApplication::Initialize() {
  int result=0;

  std::cout << "BaseApplication Initialized with configuration: " << m_Config
            << std::endl;

  return result;
}

void My::BaseApplication::Finalize() {}

void My::BaseApplication::Tick() {}

bool My::BaseApplication::IsQuit() { return m_bQuit; }
