
#include <iostream>
//using namespace std;


int iavg(int mtow, float nm, float imax, float t) // Function to calculate Average Controller Current
{
    float Multi = (nm * mtow * imax);
    int iavg = Multi / t;
    return(iavg);
}

int ebattery(float nb, float ec) // To calculate Battery Energy Capacity
{
    int eb = (nb * ec);
    return(eb);
}




int Endurance(float bs, float bc, float nb,float ec,float mtow,float nm,float imax,float t)
{
    int copy1 = ebattery(nb, ec);
    int copy2 = iavg(mtow, nm, imax, t);
    float MULTI = (bs * bc * copy1);
    int E = (MULTI / copy2);
    return E;
}




 


int Model(float nm, float wmotor, float nc, float wc, float nb, float wb, float wf) // To Calculate the Model weight of the drone
{
    int wmodel = ((nm * wmotor) + (nc * wc) + (nb * wb) + wf);
    return(wmodel);
}


 int main()
    {
        float bs, bc, nb, ec, t, nm, imax, wmotor, wc, wb, wf, nc;

        std::cout << "Enter the values for the following parameters respectively: \n";
        std::cout << "Battery Charge state: \n"; std::cin >> bs;
        std::cout << "Battery discharge state: \n"; std::cin >> bc;
        std::cout << "No.Of Batteries: \n"; std::cin >> nb;
        std::cout << "Energy capacity of one cell in a battery: \n"; std::cin >> ec;
        std::cout << "Thrust per motors: \n"; std::cin >> t;
        std::cout << "No.Of motors: \n"; std::cin >> nm;
        std::cout << "Max controller current: \n"; std::cin >> imax;
        std::cout << "Weight of one motor: \n"; std::cin >> wmotor;
        std::cout << "Weight of one controller: \n"; std::cin >> wc;
        std::cout << "Weight of of one battery: \n"; std::cin >> wb;
        std::cout << "Weight of frame: \n"; std::cin >> wf;
        std::cout << "No.Of Contorllers: \n"; std::cin >> nc;
        int MTOW = (t * (nm - 1));
        iavg(MTOW, nm, imax, t);
        ebattery(nb, ec);
        std::cout << "The Endurance of the Drone will be :  " << Endurance(bs, bc,nb,ec,MTOW,nm,imax,t) <<'\n';
        std::cout << "The Model weight of the drone will be: " << Model(nm, wmotor, nc, wc, nb, wb, wf) <<'\n';
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
