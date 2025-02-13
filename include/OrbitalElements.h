#pragma once

#include <iostream>
#include <cmath>

/* Orbital Elements */
/*
 * Orbital elements:
 *  Semi-major axis (a) - Average distance from the Sun (AU or km)
 *  Eccentricity (e) - Shape of the orbit (0 = circular, 1 = parabolic)
 *  Inclination (i) - Tilt of the orbit relative to the reference plane (ecliptic)
 *  Longitude of the ascending node (Ω) - Angle from a reference direction to the orbit's ascending node
 *  Argument of perihelion (ω) - Angle between the ascending node and perihelion
 *  Mean anomaly (M) - Fraction of the orbit's period that has elapsed since the last perihelion passage, converted into an angle.
 */

class OrbitalElements {
public:
    // Orbital Elements
    long double a;   // Semi-major axis (AU or km)
    long double e;   // Eccentricity
    long double i;   // Inclination (degrees)
    long double Ω;   // Longitude of the ascending node (degrees)
    long double ω;   // Argument of perihelion (degrees)
    long double M;   // Mean anomaly (degrees)
    long double E;   // Eccentric anomaly (computed later)

    // Additional Values
    long double M0;  // Mean anomaly at epoch
    long double n;   // Mean motion (radians per day)
    long double t;   // Current time (days)
    long double t0;  // Reference epoch (days)

    // Constants
    static constexpr long double G = 6.67430e-11L;  // Gravitational constant (m³/kg/s²)
    static constexpr long double solar_mass = 1.989e30L; // Mass of the Sun (kg)

    // Constructor
    OrbitalElements(long double semi_major, long double eccentricity, long double inclination,
                    long double ascending_node, long double perihelion, long double mean_anomaly, long double epoch)
        : a(semi_major), e(eccentricity), i(inclination),
          Ω(ascending_node), ω(perihelion), M(mean_anomaly), t0(epoch) {
        computeMeanMotion();
    }

    // Function to compute Mean Motion
    void computeMeanMotion() {
        long double a_meters = a * 1.496e+11L; // Convert AU to meters
        n = std::sqrt(G * solar_mass / std::pow(a_meters, 3)); // Radians per second
        n *= 86400.0L; // Convert to radians per day
    }

    // Compute Eccentric Anomaly using Newton-Raphson method
    void computeEccentricAnomaly() {
        long double M_radians = M * (M_PI / 180.0L); // Convert degrees to radians
        E = M_radians; // Initial guess
        for (int iter = 0; iter < 20; ++iter) { // More iterations for better precision
            E = E - (E - e * std::sin(E) - M_radians) / (1.0L - e * std::cos(E));
        }
    }
};
