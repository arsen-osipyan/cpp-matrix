#ifndef MATRIX_H
#define MATRIX_H


#include <iostream>
#include <vector>


class matrix
{
public:
  matrix (size_t, size_t);
  matrix (size_t, size_t, const std::vector<double>&);

  double& operator () (size_t, size_t);
  const double& operator () (size_t, size_t) const;

  double& at (size_t, size_t);
  const double& at (size_t, size_t) const;

  size_t width  () const { return wsize; }
  size_t height () const { return hsize; }

  void set_data (const std::vector<double>&);

  matrix& operator += (const matrix&);
  matrix& operator *= (const matrix&);
  matrix& operator *= (double);

private:
  std::vector<double> data;
  size_t hsize;
  size_t wsize;
};


class square_matrix : public matrix
{
public:
  square_matrix (size_t);
  square_matrix (size_t, const std::vector<double>&);

  double trace () const;
};


std::istream& operator >> (std::istream&, matrix&);
std::ostream& operator << (std::ostream&, const matrix&);

matrix operator + (const matrix&, const matrix&);
matrix operator * (const matrix&, const matrix&);
matrix operator * (const matrix&, double);
matrix operator += (const matrix&, const matrix&);
matrix operator *= (const matrix&, const matrix&);
matrix operator *= (const matrix&, double);


#endif // MATRIX_H
