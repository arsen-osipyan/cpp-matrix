#include <iostream>
#include "matrix.h"


int main(int argc, char* argv[])
{
  try
  {
    matrix m1{2, 2};
    matrix m2{2, 2};

    m1.set_data(std::vector<double>{1, 2, 3, 4});
    m2.set_data(std::vector<double>{1, 2, 3, 4});

    m1 += m2;

    std::cout << m1;

    return 0;
  }
  catch (std::exception& e)
  {
    std::cerr << "Error: " << e.what() << ".\n";
    return 1;
  }
  catch (...)
  {
    std::cerr << "Something went wrong.\n";
    return 2;
  }
}
