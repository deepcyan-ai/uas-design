
#include <iostream>
//using namespace std;

int main() {
  float bs, bc, nb, ec, t, nm, imax, wmotor, wc, wb, wf, nc;

  std::cout << "Enter the values for the following parameters respectively: \n";
  std::cout << "Battery Charge state: \n";
  std::cin >> bs;
  std::cout << "Battery discharge state: \n";
  std::cin >> bc;
  std::cout << "No.Of Batteries: \n";
  std::cin >> nb;
  std::cout << "Energy capacity of one cell in a battery: \n";
  std::cin >> ec;
  std::cout << "Thrust per motors: \n";
  std::cin >> t;
  std::cout << "No.Of motors: \n";
  std::cin >> nm;
  std::cout << "Max controller current: \n";
  std::cin >> imax;
  std::cout << "Weight of one motor: \n";
  std::cin >> wmotor;
  std::cout << "Weight of one controller: \n";
  std::cin >> wc;
  std::cout << "Weight of of one battery: \n";
  std::cin >> wb;
  std::cout << "Weight of frame: \n";
  std::cin >> wf;
  std::cout << "No.Of Contorllers: \n";
  std::cin >> nc;
  std::cout << "The Endurance of the Drone will be :  " << Endurance(bs, bc, nb, ec, MTOW, nm, imax, t) << '\n';
  std::cout << "The Model weight of the drone will be: " << Model(nm, wmotor, nc, wc, nb, wb, wf) << '\n';
  if (Model(nm, wmotor, nc, wc, nb, wb, wf) < MTOW)
    std::cout << "\nModel is VALIDATED";
  else {
    std::cout << "\nSorry,The Model is NOT VALIDATED";
  }
}

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
