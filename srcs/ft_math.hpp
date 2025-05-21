#ifndef FT_MATH_HPP
#define FT_MATH_HPP
#include <stdexcept>
#include <complex>

// Valeur absolue pour les réels
template <typename T>
T ft_abs(T x)
{
    return (x < 0) ? -x : x;
}

// Racine carrée (méthode de Newton-Raphson)
template <typename T>
T ft_sqrt(T x, T epsilon = 1e-7)
{
    if (x < 0)
        throw std::invalid_argument("Negative argument for sqrt");
    if (x == 0)
        return 0;
    T guess = x;
    T prev = 0;
    while (ft_abs(guess - prev) > epsilon)
    {
        prev = guess;
        guess = (guess + x / guess) / 2;
    }
    return guess;
}

// Valeur absolue pour std::complex
template <typename T>
T ft_abs(const std::complex<T>& x)
{
    return ft_sqrt(x.real() * x.real() + x.imag() * x.imag());
}

// Conjugaison pour std::complex
template <typename T>
std::complex<T> ft_conj(const std::complex<T>& x)
{
    return std::complex<T>(x.real(), -x.imag());
}

// Partie réelle pour std::complex
template <typename T>
T ft_real(const std::complex<T>& x)
{
    return x.real();
}

#endif