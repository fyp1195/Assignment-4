// PHYS 30762 Programming in C++
// Assignment 4
// Student ID: [11069686]
// Date: [22/03/2025]
// Define the particle class with the member functions and overloaded operators
#ifndef PARTICLE_H
#define PARTICLE_H

#include <string>
#include <vector>

class particle 
{
private:
  std::string particle_name;
  std::vector<double>* four_momentum; // Dynamically allocated four-momentum

public:
  // Constructors
  particle();
  particle(const std::string& name, const std::vector<double>& momentum);

  // Copy constructor
  particle(const particle& other);

  // Destructor
  ~particle();

  // Assignment operator
  particle& operator=(const particle& other);

  // Move constructor
  particle(particle&& other) noexcept;

  // Move assignment operator
  particle& operator=(particle&& other) noexcept;

  // Getter functions
  double get_energy() const;
  double get_px() const;
  double get_py() const;
  double get_pz() const;

  // Getter function for particle name
  std::string get_name() const 
  {
    return particle_name;
  }

  // Setter functions
  void set_energy(double energy);
  void set_px(double px);
  void set_py(double py);
  void set_pz(double pz);

  // Print particle data
  void print_data() const;

  // Overloaded + operator for summing four-momenta
  particle operator+(const particle& other) const;

  // Dot product of two four-momenta
  double dot_product(const particle& other) const;
};

#endif // PARTICLE_H