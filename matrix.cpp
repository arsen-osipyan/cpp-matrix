#include "matrix.h"


/// CONSTRUCTORS
matrix::matrix (size_t h, size_t w)
  : data{ std::vector<double>(h*w) }
    , hsize{ h }
    , wsize{ w }
{ }

matrix::matrix (size_t h, size_t w, const std::vector<double>& d)
  : hsize{ h }
    , wsize{ w }
{
  if (d.size() != h*w) throw std::runtime_error{ "incorrect vector size" };
  data = d;
}

square_matrix::square_matrix (size_t s)
  : matrix(s, s)
{ }

square_matrix::square_matrix (size_t s, const std::vector<double>& d)
  : matrix(s, s, d)
{ }


/// METHODS
void matrix::set_data (const std::vector<double>& d)
{
  if (d.size() != hsize * wsize) throw std::runtime_error{ "incorrect size" };
  data = d;
}

double square_matrix::trace () const
{
  double res{};
  for (size_t i{ 0 }; i < height(); ++i)
    res += this->operator()(i, i);
  return res;
}

/// ARITHMETIC OPERATORS
matrix operator + (const matrix& m1, const matrix& m2)
{
  if (m1.width() != m2.width() || m1.height() != m2.height())
    throw std::runtime_error{ "matrices must be with the same size" };
  matrix res{m1.height(), m1.width()};
  for (size_t i{0}; i < res.height(); ++i)
  {
    for (size_t j{0}; j < res.width(); ++j)
    {
      res(i, j) = m1(i, j) + m2(i, j);
    }
  }
  return res;
}

matrix operator * (const matrix& m, double k)
{
  matrix res{ m };
  for (size_t i{0}; i < res.height(); ++i)
  {
    for (size_t j{0}; j < res.width(); ++j)
    {
      res(i, j) *= k;
    }
  }
  return res;
}

matrix operator * (const matrix& m1, const matrix& m2)
{
  if (m1.width() != m2.height())
    throw std::runtime_error{ "first matrix width must be equal to second matrix height" };
  matrix res{ m1.height(), m2.width() };
  for (size_t i{ 0 }; i < res.height(); ++i)
  {
    for (size_t j{ 0 }; j < res.width(); ++j)
    {
      double cur{};
      for (size_t t{ 0 }; t < m1.width(); ++t)
        cur += m1(i, t) * m2(t, j);
      res(i, j) = cur;
    }
  }
  return res;
}

matrix& matrix::operator += (const matrix& m)
{
  *this = *this + m;
  return *this;
}

matrix& matrix::operator *= (const matrix& m)
{
  *this = *this * m;
  return *this;
}

matrix& matrix::operator *= (double k)
{
  *this = *this * k;
  return *this;
}

/// IO OPERATORS
std::ostream& operator << (std::ostream& os, const matrix& m)
{
  for (size_t i{ 0 }; i < m.height(); ++i)
  {
    for (size_t j{ 0 }; j < m.width(); ++j)
      os << m(i, j) << ' ';
    os << '\n';
  }
  return os;
}

/// INDEXATION
double& matrix::operator () (size_t i, size_t j)
{
  return data[i*wsize + j];
}

const double& matrix::operator () (size_t i, size_t j) const
{
  return data[i*wsize + j];
}


double& matrix::at (size_t i, size_t j)
{
  if (i >= hsize || j >= wsize) throw std::out_of_range{ "bad element index" };
  return data[i*wsize + j];
}

const double& matrix::at (size_t i, size_t j) const
{
  if (i >= hsize || j >= wsize) throw std::out_of_range{ "bad element index" };
  return data[i*wsize + j];
}
