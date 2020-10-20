/**
 * @{
 * \file
 * \brief [Runge Kutta fourth order](https://en.wikipedia.org/wiki/Runge%E2%80%93Kutta_methods) method implementation
 *
 * \author [Rudra Prasad Das](http://github.com/rudra697)
 *
 * \details
 * It solves the unknown value of y 
 * for a given value of x
 * only first oreder differential equations
 * can be solved
 * \example
 * it solves dy/dx=(x-y)/2 at a 
 * given x for given initial 
 * conditions
 * There can be many such equations 
 * **/
#include <iostream> /// for io operations
#include<vector> ///for using the vector container
#include <cassert>  /// asserting the test functions
/**
 * @namespace numerical_methods
 * @brief Numerical Methods
 */
/**
 * @brief The change() function is used 
 * to return the updated iterative value corresponding 
 * to the given function
 * @param x is the value corresponding to the x coordinate
 * @param y is the value corresponding to the y coordinate 
 * @returns the computed function value at that call
 */
static double change(double x, double y) 
{ 
	double val=((x - y)/2.0); 
	return val;
} 
namespace numerical_methods {
/**
 * @namespace runge_kutta
 * @brief Functions for [Runge Kutta fourth order](https://en.wikipedia.org/wiki/Runge%E2%80%93Kutta_methods) method
 */
namespace runge_kutta {

/**
 * @brief the Runge Kutta method finds the value of integration of a function in the given limits.
 * the lower limit of integration as the initial value and the upper limit is the given x
 * @param init_x is the value of initial x and is updated after each call
 * @param init_y is the value of initial x and is updated after each call
 * @param x is current iteration at which the function needs to be evaluated
 * @param h is the step value 
 * @returns the value of y at thr required value of x from the initial conditions
 */
double rungeKutta(double init_x, double init_y, double x, double h) 
{ 
	 
	  // Count number of iterations 
	  //using step size or 
	  // step height h 
	  
	 
	  // n calucates the number of iterations
	  // k1,k2,k3,k4 are the Runge Kutta variables 
	  // used for calculation of y at each iteration
	  
	 int n = static_cast<int>((x - init_x) / h); 
	  // used a vector container for the variables
	 std::vector<double> k(4,0.0);
    
	
	  // Iterate for number of iterations 
	 
	double y = init_y; 
	for (int i=1; i<=n; i++) 
	{ 
						
		 // Apply Runge Kutta Formulas 
		 // to find next value of y 
		k[0] = h*change(init_x, y); 
		k[1] = h*change(init_x + 0.5*h, y + 0.5*k[0]); 
		k[2] = h*change(init_x + 0.5*h, y + 0.5*k[1]); 
		k[3] = h*change(init_x + h, y + k[2]); 
		 
		
		// Update next value of y 
		
		y = y + (1.0/6.0)*(k[0] + 2*k[1] + 2*k[2] + k[3]);
		
		// Update next value of x 
		
		init_x = init_x + h; 
	} 

	return y; 
} 

} // namespace runge_kutta
} // namespace numerical_methods
/**
 * @brief the functions are for self test
 * @returns void and prints the success of rungeKutta function
 */
	static void test()
	{
		std::cout << "Test 1...." << "\n";
		double valfirst=numerical_methods::runge_kutta::rungeKutta(2,3,4,0.2); // Tests the function with pre calculated values
		assert(valfirst==3.10364);
		std::cout << "Passed Test 1\n";

		std::cout << "Test 2...." << "\n";
		double valsec=numerical_methods::runge_kutta::rungeKutta(1,2,5,0.1);  // The value of step changed
		assert(valsec==3.406);
		std::cout << "Passed Test 2\n";
		
		std::cout << "Test 3...." << "\n";
		double valfirst=numerical_methods::runge_kutta::rungeKutta(-1,3,4,0.1); // Tested with negative value
		assert(valfirst==2.49251);
		std::cout << "Passed Test 3\n";
	}
	
	
/**
 * @brief Main function
 * @returns 0 on exit 
 */
int main() 
{ 
	std::cout << "The Runge Kutta function will be tested on the basis of precomputed values\n";
	test();  // Execute the tests
	return 0; 
} 
