#ifndef MATRIX_H
#define MATRIX_H


#include <vector>


class matrix
{
public:
  matrix (size_t, size_t);
  matrix (const std::vector<double>&);

  double& operator () (size_t, size_t);
  const double& operator () (size_t, size_t) const;

private:
  std::vector<double> data;
  size_t wsize;
  size_t hsize;
};


#endif // MATRIX_H
