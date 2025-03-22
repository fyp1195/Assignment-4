// PHYS 30762 Programming in C++
// Assignment 4
// Student ID: [11069686]
// Date: [22/03/2025]
// Main function to test the particle class
#include "particle.h"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <stdexcept>

// Main program
int main()
{
  // Create the following particles: two electrons, four muons, one antielectron, one antimuon
  particle electron1("electron", {0.511, 0.1, 0.2, 0.3});
  std::cout << "Created Electron 1:" << std::endl;
  particle electron2("electron", {0.511, -0.1, -0.2, -0.3});
  std::cout << "Created Electron 2:" << std::endl;
  particle muon1("muon", {105.7, 1.0, 2.0, 3.0});
  std::cout << "Created Muon 1:" << std::endl;
  particle muon2("muon", {105.7, -1.0, -2.0, -3.0});
  std::cout << "Created Muon 2:" << std::endl;
  particle tau1("tau", {1777, 0.0, 0.0, 0.0});
  std::cout << "Created Tau 1:" << std::endl;
  particle tau2("tau", {1777, 0.5, 1.5, 2.5});
  std::cout << "Created Tau 2:" << std::endl;

  // Print out the data from all the particles
  std::cout << "---------------------" << std::endl;
  std::cout << "Initial Particles:" << std::endl;
  electron1.print_data();
  electron2.print_data();
  muon1.print_data();
  muon2.print_data();
  tau1.print_data();
  tau2.print_data();
  std::cout << "---------------------" << std::endl;

  // Sum the four-momenta of the two electrons
  particle combined_electron = electron1 + electron2;
  std::cout << "Combined Electron:" << std::endl;
  combined_electron.print_data();
  std::cout << "---------------------" << std::endl;

  // Take the dot product of the two four-muons
  double dot = muon1.dot_product(muon2);
  std::cout << "Dot Product of Muon1 and Muon2: " << dot << std::endl;
  std::cout << "---------------------" << std::endl;

  // Assignment operator of the first electron to a new electron
  particle electron3;
  electron3 = electron1;
  std::cout << "Copied Electron (Assignment Operator):" << std::endl;
  std::cout << "Copied Electron 1:" << std::endl;
  electron3.print_data();
  std::cout << "---------------------" << std::endl;

  // Copy constructor of the first muon to a new muon
  particle muon3(muon1);
  std::cout << "Copied Muon (Copy Constructor):" << std::endl;
  std::cout << "Copied Muon 1:" << std::endl;
  muon3.print_data();
  std::cout << "---------------------" << std::endl;

  // Assign the first tau to another different tau using the move assignment Operator
  particle tau3;
  tau3 = std::move(tau1);
  std::cout << "Moved Tau (Move Assignment Operator):" << std::endl;
  std::cout << "Moved Tau 1 to another different tau:" << std::endl;
  tau3.print_data();
  std::cout << "Tau 1 after move assignment:" << std::endl;
  tau1.print_data();
  std::cout << "---------------------" << std::endl;

  // Move the second tau into the first tau using the move constructor
  particle tau4(std::move(tau2));
  tau1 = std::move(tau4);
  std::cout << "Moved Tau (Move Constructor):" << std::endl;
  std::cout << "Moved Tau 2 into Tau 1:" << std::endl;
  tau1.print_data();
  std::cout << "Tau 2 after move constructor:" << std::endl;
  tau2.print_data();
  std::cout << "---------------------" << std::endl;

  return 0;
}