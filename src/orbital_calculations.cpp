#include "orbital_calculations.h"
#include <cmath>

void computePositionAndVelocity(const OrbitalElements& elements, long double& x, long double& y, long double& z, long double& vx, long double& vy, long double& vz) {
    // Convert angles from degrees to radians
    long double i_rad = elements.i * (M_PI / 180.0L);
    long double Ω_rad = elements.Ω * (M_PI / 180.0L);
    long double ω_rad = elements.ω * (M_PI / 180.0L);
    long double E_rad = elements.E;

    // Compute the true anomaly (ν)
    long double ν = 2.0L * std::atan(std::sqrt((1.0L + elements.e) / (1.0L - elements.e)) * std::tan(E_rad / 2.0L));

    // Compute the distance from the central body (r)
    long double r = elements.a * (1.0L - elements.e * std::cos(E_rad));

    // Compute the position in the orbital plane (x', y')
    long double x_prime = r * std::cos(ν);
    long double y_prime = r * std::sin(ν);

    // Compute the position in 3D space (x, y, z)
    x = (std::cos(ω_rad) * std::cos(Ω_rad) - std::sin(ω_rad) * std::sin(Ω_rad) * std::cos(i_rad)) * x_prime +
        (-std::sin(ω_rad) * std::cos(Ω_rad) - std::cos(ω_rad) * std::sin(Ω_rad) * std::cos(i_rad)) * y_prime;
    y = (std::cos(ω_rad) * std::sin(Ω_rad) + std::sin(ω_rad) * std::cos(Ω_rad) * std::cos(i_rad)) * x_prime +
        (-std::sin(ω_rad) * std::sin(Ω_rad) + std::cos(ω_rad) * std::cos(Ω_rad) * std::cos(i_rad)) * y_prime;
    z = (std::sin(ω_rad) * std::sin(i_rad)) * x_prime + (std::cos(ω_rad) * std::sin(i_rad)) * y_prime;

    // Compute the velocity in the orbital plane (vx', vy')
    long double vx_prime = -std::sin(E_rad) * elements.n * elements.a / (1.0L - elements.e * std::cos(E_rad));
    long double vy_prime = std::sqrt(1.0L - elements.e * elements.e) * std::cos(E_rad) * elements.n * elements.a / (1.0L - elements.e * std::cos(E_rad));

    // Compute the velocity in 3D space (vx, vy, vz)
    vx = (std::cos(ω_rad) * std::cos(Ω_rad) - std::sin(ω_rad) * std::sin(Ω_rad) * std::cos(i_rad)) * vx_prime +
         (-std::sin(ω_rad) * std::cos(Ω_rad) - std::cos(ω_rad) * std::sin(Ω_rad) * std::cos(i_rad)) * vy_prime;
    vy = (std::cos(ω_rad) * std::sin(Ω_rad) + std::sin(ω_rad) * std::cos(Ω_rad) * std::cos(i_rad)) * vx_prime +
         (-std::sin(ω_rad) * std::sin(Ω_rad) + std::cos(ω_rad) * std::cos(Ω_rad) * std::cos(i_rad)) * vy_prime;
    vz = (std::sin(ω_rad) * std::sin(i_rad)) * vx_prime + (std::cos(ω_rad) * std::sin(i_rad)) * vy_prime;
}