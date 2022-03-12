#include <chrono>

#define TICK(x) auto bench##x = std::chrono::steady_clock::now();
#define TOCK(x) std::cout << #x": " << std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::steady_clock::now() - bench##x).count() << "s" << std::endl;
