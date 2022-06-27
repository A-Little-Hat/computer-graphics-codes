//hermite.cpp

/*
https://people.sc.fsu.edu/~jburkardt/cpp_src/hermite_cubic/hermite_cubic.html
*/



# include <cmath>
# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <ctime>
using namespace std;
double hermite_cubic_integral ( double x1, double f1, double d1, double x2,
  double f2, double d2 );
double hermite_cubic_integrate ( double x1, double f1, double d1, double x2,
  double f2, double d2, double a, double b );
double *hermite_cubic_lagrange_integral ( double x1, double x2 );
double *hermite_cubic_lagrange_integrate ( double x1, double x2, double a,
  double b );
void hermite_cubic_lagrange_value ( double x1, double x2, int n, double x[],
  double f[], double d[], double s[], double t[] );
double hermite_cubic_spline_integral ( int nn, double xn[], double fn[],
  double dn[] );
double *hermite_cubic_spline_integrate ( int nn, double xn[], double fn[],
  double dn[], int n, double a[], double b[] );
double *hermite_cubic_spline_quad_rule ( int nn, double xn[] );
void hermite_cubic_spline_value ( int nn, double xn[], double fn[],
  double dn[], int n, double x[], double f[], double d[], double s[],
  double t[] );
void hermite_cubic_to_power_cubic ( double x1, double f1, double d1, double x2,
  double f2, double d2, double *c0, double *c1, double *c2, double *c3 );
void hermite_cubic_value ( double x1, double f1, double d1, double x2,
  double f2, double d2, int n, double x[], double f[], double d[],
  double s[], double t[] );
void power_cubic_to_hermite_cubic ( double c0, double c1, double c2, double c3,
  double x1, double x2, double *f1, double *d1, double *f2, double *d2 );
double r8_uniform_01 ( int *seed );
void r8vec_bracket3 ( int n, double t[], double tval, int *left );
double *r8vec_even_new ( int n, double alo, double ahi );
double *r8vec_uniform_01_new ( int n, int *seed );
void timestamp ( );
double hermite_cubic_integral ( double x1, double f1, double d1, double x2, double f2, double d2 )
{
  double h;
  double q;
  h = x2 - x1;
  q = 0.5 * h * ( f1 + f2 + h * ( d1 - d2 ) / 6.0 );
  return q;
}
double hermite_cubic_integrate ( double x1, double f1, double d1, double x2, double f2, double d2, double a, double b )
{
  double dterm;
  double fterm;
  double h;
  double phia1;
  double phia2;
  double phib1;
  double phib2;
  double psia1;
  double psia2;
  double psib1;
  double psib2;
  double q;
  double ta1;
  double ta2;
  double tb1;
  double tb2;
  double ua1;
  double ua2;
  double ub1;
  double ub2;
  h = x2 - x1;
  ta1 = ( a - x1 ) / h;
  ta2 = ( x2 - a ) / h;
  tb1 = ( b - x1 ) / h;
  tb2 = ( x2 - b ) / h;
  ua1 = ta1 * ta1 * ta1;
  phia1 = ua1 * ( 2.0 - ta1 );
  psia1 = ua1 * ( 3.0 * ta1 - 4.0 );
  ua2 = ta2 * ta2 * ta2;
  phia2 =  ua2 * ( 2.0 - ta2 );
  psia2 = -ua2 * ( 3.0 * ta2 - 4.0 );
  ub1 = tb1 * tb1 * tb1;
  phib1 = ub1 * ( 2.0 - tb1 );
  psib1 = ub1 * ( 3.0 * tb1 - 4.0 );
  ub2 = tb2 * tb2 * tb2;
  phib2 =  ub2 * ( 2.0 - tb2 );
  psib2 = -ub2 * ( 3.0 * tb2 - 4.0 );
  fterm =   f1 * ( phia2 - phib2 ) + f2 * ( phib1 - phia1 );
  dterm = ( d1 * ( psia2 - psib2 ) + d2 * ( psib1 - psia1 ) ) * ( h / 6.0 );
  q = 0.5 * h * ( fterm + dterm );
  return q;
}
double *hermite_cubic_lagrange_integral ( double x1, double x2 )
{
  double h;
  double *q;
  q = new double[4];
  h = x2 - x1;
  q[0] =   h     / 2.0;
  q[1] =   h * h / 12.0;
  q[2] =   h     / 2.0;
  q[3] = - h * h / 12.0;
  return q;
}
double *hermite_cubic_lagrange_integrate ( double x1, double x2, double a, double b )
{
  double h;
  double phia1;
  double phia2;
  double phib1;
  double phib2;
  double psia1;
  double psia2;
  double psib1;
  double psib2;
  double *q;
  double ta1;
  double ta2;
  double tb1;
  double tb2;
  double ua1;
  double ua2;
  double ub1;
  double ub2;
  h = x2 - x1;
  ta1 = ( a - x1 ) / h;
  ta2 = ( x2 - a ) / h;
  tb1 = ( b - x1 ) / h;
  tb2 = ( x2 - b ) / h;
  ua1 = ta1 * ta1 * ta1;
  phia1 = ua1 * ( 2.0 - ta1 );
  psia1 = ua1 * ( 3.0 * ta1 - 4.0 );
  ua2 = ta2 * ta2 * ta2;
  phia2 =  ua2 * ( 2.0 - ta2 );
  psia2 = -ua2 * ( 3.0 * ta2 - 4.0 );
  ub1 = tb1 * tb1 * tb1;
  phib1 = ub1 * ( 2.0 - tb1 );
  psib1 = ub1 * ( 3.0 * tb1 - 4.0 );
  ub2 = tb2 * tb2 * tb2;
  phib2 =  ub2 * ( 2.0 - tb2 );
  psib2 = -ub2 * ( 3.0 * tb2 - 4.0 );
  q = new double[4];
  q[0] = 0.5 * h * ( phia2 - phib2 );
  q[1] = 0.5 * h * ( psia2 - psib2 ) * ( h / 6.0 );
  q[2] = 0.5 * h * ( phib1 - phia1 );
  q[3] = 0.5 * h * ( psib1 - psia1 ) * ( h / 6.0 );
  return q;
}
void hermite_cubic_lagrange_value ( double x1, double x2, int n, double x[], double f[], double d[], double s[], double t[] )
{
  double dx;
  double h;
  int j;
  h = x2 - x1;
  for ( j = 0; j < n; j++ )
  {
    dx = x[j] - x1;
    f[0+j*4] = 1.0 + ( ( dx * dx ) / ( h * h )     ) * ( - 3.0 + ( dx / h ) *  2.0 );
    d[0+j*4] =       ( dx          / ( h * h )     ) * ( - 6.0 + ( dx / h ) *  6.0 );
    s[0+j*4] =       ( 1.0         / ( h * h )     ) * ( - 6.0 + ( dx / h ) * 12.0 );
    t[0+j*4] =       ( 1.0         / ( h * h * h ) )                        * 12.0;
    f[1+j*4] = dx  + ( ( dx * dx ) / h         ) * ( - 2.0 + ( dx / h )       );
    d[1+j*4] = 1.0 + ( dx          / h         ) * ( - 4.0 + ( dx / h ) * 3.0 );
    s[1+j*4] =       ( 1.0         / h         ) * ( - 4.0 + ( dx / h ) * 6.0 );
    t[1+j*4] =       ( 1.0         / ( h * h ) )                        * 6.0;
    f[2+j*4] = ( ( dx * dx ) / ( h * h )     ) * ( 3.0 -  2.0 * ( dx / h ) );
    d[2+j*4] = ( dx          / ( h * h )     ) * ( 6.0 -  6.0 * ( dx / h ) );
    s[2+j*4] = ( 1.0         / ( h * h )     ) * ( 6.0 - 12.0 * ( dx / h ) );
    t[2+j*4] = ( 1.0         / ( h * h * h ) ) * (     - 12.0              );
    f[3+j*4] = ( ( dx * dx ) / h ) * ( - 1.0 + ( dx / h )       );
    d[3+j*4] = ( dx          / h ) * ( - 2.0 + ( dx / h ) * 3.0 );
    s[3+j*4] = ( 1.0         / h ) * ( - 2.0 + ( dx / h ) * 6.0 );
    t[3+j*4] = ( 1.0         / h )                        * 6.0;
  }
  return;
}
double hermite_cubic_spline_integral ( int nn, double xn[], double fn[], double dn[] )
{
  int i;
  double q;
  q = 0.0;
  for ( i = 0; i < nn - 1; i++ )
  {
    q = q +
    0.5 * ( xn[i+1] - xn[i] ) * ( fn[i] + fn[i+1]
        + ( xn[i+1] - xn[i] ) * ( dn[i] - dn[i+1] ) / 6.0 );
  }
  return q;
}
double *hermite_cubic_spline_integrate ( int nn, double xn[], double fn[], double dn[], int n, double a[], double b[] )
{
  double aa;
  double bb;
  int i;
  int ii;
  int j;
  int k;
  double *q;
  double s;
  q = new double[n];
  i = n / 2;
  j = n / 2;
  for ( ii = 0; ii < n; ii++ )
  {
    q[ii] = 0.0;
    if ( a[ii] <= b[ii] )
    {
      aa = a[ii];
      bb = b[ii];
      s = + 1.0;
    }
    else
    {
      aa = b[ii];
      bb = a[ii];
      s = - 1.0;
    }
    r8vec_bracket3 ( nn, xn, aa, &i );
    r8vec_bracket3 ( nn, xn, bb, &j );
    if ( i == j )
    {
      q[ii] = hermite_cubic_integrate ( xn[i], fn[i], dn[i],
        xn[i+1], fn[i+1], dn[i+1], aa, bb );
    }
    else
    {
      q[ii] = hermite_cubic_integrate ( xn[i], fn[i], dn[i],
        xn[i+1], fn[i+1], dn[i+1], aa, xn[i+1] );
      for ( k = i + 1; k < j; k++ )
      {
        q[ii] = q[ii] +  hermite_cubic_integral ( xn[k], fn[k], dn[k],
          xn[k+1], fn[k+1], dn[k+1] );
      }
      q[ii] = q[ii] + hermite_cubic_integrate ( xn[j], fn[j], dn[j],
        xn[j+1], fn[j+1], dn[j+1], xn[j], bb );
    }
    q[ii] = s * q[ii];
  }
  return q;
}
double *hermite_cubic_spline_quad_rule ( int nn, double xn[] )
{
  int j;
  double *w;
  w = new double[2*nn];
  w[0+0*2] = 0.5 * ( xn[1] - xn[0] );
  for ( j = 1; j < nn - 1; j++ )
  {
    w[0+j*2] = 0.5 * ( xn[j+1] - xn[j-1] );
  }
  w[0+(nn-1)*2] = 0.5 * ( xn[nn-1] - xn[nn-2]   );
  w[1+0*2] = pow ( xn[1] - xn[0], 2 ) / 12.0;
  for ( j = 1; j < nn - 1; j++ )
  {
    w[1+j*2] = ( xn[j+1] - xn[j-1] )
      * ( xn[j+1] - 2.0 * xn[j] + xn[j-1] ) / 12.0;
  }
  w[1+(nn-1)*2] = - pow ( xn[nn-2] - xn[nn-1], 2 ) / 12.0;
  return w;
}
void hermite_cubic_spline_value ( int nn, double xn[], double fn[], double dn[], int n, double x[], double f[], double d[], double s[], double t[] )
{
  int i;
  int left;
  left = n / 2;
  for ( i = 0; i < n; i++ )
  {
    r8vec_bracket3 ( nn, xn, x[i], &left );
    hermite_cubic_value ( xn[left], fn[left], dn[left], xn[left+1],
      fn[left+1], dn[left+1], 1, x+i, f+i, d+i, s+i, t+i );
  }
  return;
}
void hermite_cubic_to_power_cubic ( double x1, double f1, double d1, double x2, double f2, double d2, double *c0, double *c1, double *c2, double *c3 )
{
  double df;
  double h;
  h =    x2 - x1;
  df = ( f2 - f1 ) / h;
  *c0 = f1;
  *c1 = d1;
  *c2 = - ( 2.0 * d1 - 3.0 * df + d2 ) / h;
  *c3 =   (       d1 - 2.0 * df + d2 ) / h / h;
  *c2 = *c2 - x1 * *c3;
  *c1 = *c1 - x1 * *c2;
  *c0 = *c0 - x1 * *c1;
  *c2 = *c2 - x1 * *c3;
  *c1 = *c1 - x1 * *c2;
  *c2 = *c2 - x1 * *c3;
  return;
}
void hermite_cubic_value ( double x1, double f1, double d1, double x2, double f2, double d2, int n, double x[], double f[], double d[], double s[], double t[] )
{
  double c2;
  double c3;
  double df;
  double h;
  int i;
  h =    x2 - x1;
  df = ( f2 - f1 ) / h;
  c2 = - ( 2.0 * d1 - 3.0 * df + d2 ) / h;
  c3 =   (       d1 - 2.0 * df + d2 ) / h / h;
  for ( i = 0; i < n; i++ )
  {
    f[i] =       f1 + ( x[i] - x1 ) * ( d1
                    + ( x[i] - x1 ) * ( c2
                    + ( x[i] - x1 ) *   c3 ) );
    d[i] =       d1 + ( x[i] - x1 ) * ( 2.0 * c2
                    + ( x[i] - x1 ) * 3.0 * c3 );
    s[i] = 2.0 * c2 + ( x[i] - x1 ) * 6.0 * c3;
    t[i] = 6.0 * c3;
  }
  return;
}
void power_cubic_to_hermite_cubic ( double c0, double c1, double c2, double c3, double x1, double x2, double *f1, double *d1, double *f2, double *d2 )
{
  *f1 = c0 + x1 * ( c1 + x1 * (       c2 + x1       * c3 ) );
  *d1 =             c1 + x1 * ( 2.0 * c2 + x1 * 3.0 * c3 );
  *f2 = c0 + x2 * ( c1 + x2 * (       c2 + x2       * c3 ) );
  *d2 =             c1 + x2 * ( 2.0 * c2 + x2 * 3.0 * c3 );
  return;
}
double r8_uniform_01 ( int *seed )
{
  int i4_huge = 2147483647;
  int k;
  double r;
  if ( *seed == 0 )
  {
    std::cerr << "\n";
    std::cerr << "R8_UNIFORM_01 - Fatal error!\n";
    std::cerr << "  Input value of SEED = 0.\n";
    std::exit ( 1 );
  }
  k = *seed / 127773;
  *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;
  if ( *seed < 0 )
  {
    *seed = *seed + i4_huge;
  }
  r = ( double ) ( *seed ) * 4.656612875E-10;
  return r;
}
void r8vec_bracket3 ( int n, double t[], double tval, int *left )
{
  int high;
  int low;
  int mid;
  if ( n < 2 )
  {
    std::cerr << "\n";
    std::cerr << "R8VEC_BRACKET3 - Fatal error!\n";
    std::cerr << "  N must be at least 2.\n";
    std::exit ( 1 );
  }
  if ( *left < 0 || n - 2 < *left )
  {
    *left = ( n - 1 ) / 2;
  }
  if ( tval < t[*left] )
  {
    if ( *left == 0 )
    {
      return;
    }
    else if ( *left == 1 )
    {
      *left = 0;
      return;
    }
    else if ( t[*left-1] <= tval )
    {
      *left = *left - 1;
      return;
    }
    else if ( tval <= t[1] )
    {
      *left = 0;
      return;
    }
    low = 1;
    high = *left - 2;

    for ( ; ; )
    {
      if ( low == high )
      {
        *left = low;
        return;
      }

      mid = ( low + high + 1 ) / 2;

      if ( t[mid] <= tval )
      {
        low = mid;
      }
      else
      {
        high = mid - 1;
      }
    }
  }
  else if ( t[*left+1] < tval )
  {
    if ( *left == n - 2 )
    {
      return;
    }
    else if ( *left == n - 3 )
    {
      *left = *left + 1;
      return;
    }
    else if ( tval <= t[*left+2] )
    {
      *left = *left + 1;
      return;
    }
    else if ( t[n-2] <= tval )
    {
      *left = n - 2;
      return;
    }
    low = *left + 2;
    high = n - 3;

    for ( ; ; )
    {
      if ( low == high )
      {
        *left = low;
        return;
      }

      mid = ( low + high + 1 ) / 2;

      if ( t[mid] <= tval )
      {
        low = mid;
      }
      else
      {
        high = mid - 1;
      }
    }
  }
  else
  {
  }
  return;
}
double *r8vec_even_new ( int n, double alo, double ahi )
{
  double *a;
  int i;

  a = new double[n];

  if ( n == 1 )
  {
    a[0] = 0.5 * ( alo + ahi );
  }
  else
  {
    for ( i = 0; i < n; i++ )
    {
      a[i] = ( ( double ) ( n - i - 1 ) * alo
             + ( double ) (     i     ) * ahi )
             / ( double ) ( n     - 1 );
    }
  }

  return a;
}
double *r8vec_uniform_01_new ( int n, int *seed )
{
  int i;
  int i4_huge = 2147483647;
  int k;
  double *r;

  if ( *seed == 0 )
  {
    cerr << "\n";
    cerr << "R8VEC_UNIFORM_01_NEW - Fatal error!\n";
    cerr << "  Input value of SEED = 0.\n";
    exit ( 1 );
  }
  r = new double[n];
  for ( i = 0; i < n; i++ )
  {
    k = *seed / 127773;
    *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;
    if ( *seed < 0 )
    {
      *seed = *seed + i4_huge;
    }
    r[i] = ( double ) ( *seed ) * 4.656612875E-10;
  }
  return r;
}
void timestamp ( )
{
# define TIME_SIZE 40
  static char time_buffer[TIME_SIZE];
  const struct std::tm *tm_ptr;
  std::time_t now;
  now = std::time ( NULL );
  tm_ptr = std::localtime ( &now );
  std::strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm_ptr );
  std::cout << time_buffer << "\n";
  return;
# undef TIME_SIZE
}
