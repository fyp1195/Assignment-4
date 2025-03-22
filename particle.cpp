// PHYS 30762 Programming in C++
// Assignment 4
// Student ID: [11069686]
// Date: [22/03/2025]
// implementation of the particle class

#include "particle.h"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <stdexcept>

// Default constructor
particle::particle() 
  : particle_name(""), four_momentum(new std::vector<double>{0, 0, 0, 0})
{
}

// Parameterized constructor
particle::particle(const std::string& name, const std::vector<double>& momentum)
{
  particle_name = name;
  four_momentum = new std::vector<double>(momentum);
  std::cout << "Calling parameterized constructor" << std::endl;
}

// Copy constructor
particle::particle(const particle& other)
{
  std::cout << "Calling copy constructor" << std::endl;
  particle_name = other.particle_name;
  four_momentum = new std::vector<double>(*other.four_momentum);
}

// Destructor
particle::~particle()
{
  std::cout << "Calling destructor" << std::endl;
  delete four_momentum; // Free dynamically allocated memory
}

// Assignment operator
particle& particle::operator=(const particle& other)
{
  std::cout << "Calling Assignment Operator" << std::endl;
  if (this != &other) 
  { // Avoid self-assignment
    particle_name = other.particle_name;
    *four_momentum = *other.four_momentum;
  }
  return *this;
}

// Move constructor
particle::particle(particle&& other) noexcept
{
  std::cout << "Calling Move Constructor" << std::endl;
  particle_name = std::move(other.particle_name);
  four_momentum = other.four_momentum; // Steal the pointer
  other.four_momentum = nullptr; // Reset the source object's pointer
}

// Move assignment operator
particle& particle::operator=(particle&& other) noexcept
{
  std::cout << "Calling Move Assignment Operator" << std::endl;
  if (this != &other) 
  { // Avoid self-assignment
    particle_name = std::move(other.particle_name);
    delete four_momentum; // Free current object's resources
    four_momentum = other.four_momentum;
    other.four_momentum = nullptr; // Reset the source object's pointer
  }
  return *this;
}

// Getter functions
double particle::get_energy() const 
{ 
  return (*four_momentum)[0]; 
}

double particle::get_px() const 
{ 
  return (*four_momentum)[1]; 
}

double particle::get_py() const 
{ 
  return (*four_momentum)[2]; 
}

double particle::get_pz() const 
{ 
  return (*four_momentum)[3]; 
}

// Setter functions
void particle::set_energy(double energy)
{
  if (energy >= 0) 
  {
    (*four_momentum)[0] = energy;
  } 
  else 
  {
    std::cerr << "Energy must be non-negative" << std::endl;
  }
}

void particle::set_px(double px) 
{ 
  (*four_momentum)[1] = px; 
}

void particle::set_py(double py) 
{ 
  (*four_momentum)[2] = py; 
}

void particle::set_pz(double pz) 
{ 
  (*four_momentum)[3] = pz; 
}

// Print particle data
void particle::print_data() const
{
  // Print particle name
  if (particle_name.empty()) 
  {
    std::cout << "Particle: unknown" << std::endl;
  } 
  else 
  {
    std::cout << "Particle: " << particle_name << std::endl;
  }

  // Check if four_momentum is nullptr
  if (four_momentum == nullptr) 
  {
    std::cout << "Four-Momentum: moved" << std::endl;
  } 
  else 
  {
    // Check if particle name is valid
    if (particle_name != "electron" && particle_name != "muon" && 
        particle_name != "tau" && particle_name != "combined_particle")
    {
      std::cerr << "Invalid particle name" << std::endl;
      std::cout << "Particle: unknown" << std::endl;
    }

    // Check if four-momentum size is not 4
    if (four_momentum->size() != 4) 
    {
      std::cout << "Error: Invalid four-momentum size (must be 4), set the four-momentum value to (0,0,0,0)" << std::endl;
      const_cast<std::vector<double>&>(*four_momentum) = {0, 0, 0, 0};
    }
    // Check if energy value is less than 0
    else if ((*four_momentum)[0] < 0) 
    {
      std::cout << "Error: Energy can't be negative, set the four-momentum value to (0,0,0,0)" << std::endl;
      const_cast<std::vector<double>&>(*four_momentum) = {0, 0, 0, 0};
    }
    // Print four-momentum
    else 
    {
      std::cout << "Four-Momentum: (" << (*four_momentum)[0] << ", " << (*four_momentum)[1] << ", "
                << (*four_momentum)[2] << ", " << (*four_momentum)[3] << ")" << std::endl;
    }
  }

  // Print memory location
  std::cout << "Memory Location: " << this << std::endl;
}

// Overloaded + operator for summing four-momenta
particle particle::operator+(const particle& other) const
{
  std::vector<double> new_momentum = {
    (*four_momentum)[0] + (*other.four_momentum)[0],
    (*four_momentum)[1] + (*other.four_momentum)[1],
    (*four_momentum)[2] + (*other.four_momentum)[2],
    (*four_momentum)[3] + (*other.four_momentum)[3]
  };
  return particle("combined_particle", new_momentum);
}

// Dot product of two four-momenta
double particle::dot_product(const particle& other) const
{
  return (*four_momentum)[0] * (*other.four_momentum)[0] -
         (*four_momentum)[1] * (*other.four_momentum)[1] -
         (*four_momentum)[2] * (*other.four_momentum)[2] -
         (*four_momentum)[3] * (*other.four_momentum)[3];
}
