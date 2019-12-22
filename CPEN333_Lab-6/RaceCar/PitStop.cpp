#include "Car.h"
#include "Supervisor.h"
#include "Refuel.h"
#include "Jacks.h"
#include "Nuts.h"
#include "Wheel_Removal.h"
#include "Wheel_Securing.h"
#include "Semaphores.h"

//CSemaphore light("Pit_entry_light", 15, 15);	//Pit entrance light, GREEN when all technicians are ready, Initiall Green
////CSemaphore light2("Pit_exit_light", 0, 15);		//Pit exit light, Initially RED, Wait for all techs (except Supervisor) to be done
//CSemaphore fuel("Fuel_car", 0, 1);			//Refuel Tech waits for 2 JACK tecks to start raising car
//
////====================
//// Jacking technicians
////=====================
//CSemaphore StartJacks("Start_Jacks", 0, 2);	//Supervisor signals Jacks
//CSemaphore jackFup("Raise_Front", 0, 1);	//Raise front of car
//CSemaphore jackBup("Raise_Back", 0, 1);		//Raise back
//CSemaphore jackFdown("Lower_Front", 0, 1);	//Lower front of car
//CSemaphore jackBdown("Lower_Back", 0, 1);		//Lower back
//
////====================
//// Wheel technicians
////=====================
////				  BACK
////		Tire3 []--|	  |--[] Tire 4
////				  |   |
////			      |	  |
////		Tire2 []--|   |--[] Tire 1
////					FRONT
//CSemaphore FrontWheels("Tires_Front", 0, 2);// Initally 0 since they haven't been changed yet
//CSemaphore BackWheels("Tires_Back", 0, 2);// Initally 0 since they haven't been changed yet
////Nut techs
//CSemaphore Nut1("Nut1", 0, 1);			//Nut technician waiting for Front jacked up
//CSemaphore Nut2("Nut2", 0, 1);			//Nut technician waiting for Front jacked up
//CSemaphore Nut3("Nut3", 0, 1);			//Nut technician waiting for Back be jacked up
//CSemaphore Nut4("Nut4", 0, 1);			//Nut technician waiting for Back be jacked up
////Wheel removal
//CSemaphore Off1("Off1", 0, 1);			//Wheel removal waiting until NUT tech is done
//CSemaphore Off2("Off2", 0, 1);			//Wheel removal waiting until NUT tech is done
//CSemaphore Off3("Off3", 0, 1);			//Wheel removal waiting until NUT tech is done
//CSemaphore Off4("Off4", 0, 1);			//Wheel removal waiting until NUT tech is done
////Wheel securing
//CSemaphore On1("On1", 0, 1);			//Wheel securing waits for REMOVAL tech to finish
//CSemaphore On2("On2", 0, 1);			//Wheel securing waits for REMOVAL tech to finish
//CSemaphore On3("On3", 0, 1);			//Wheel securing waits for REMOVAL tech to finish
//CSemaphore On4("On4", 0, 1);			//Wheel securing waits for REMOVAL tech to finish
////========================
//// End of Wheel Techs
////========================
int main()
{
	//Creating some Cars
	Car car1(1), car2(2), car3(3), car4(4), car5(5), car6(6), car7(7), car8(8), car9(9), car10(10);

	// Creating instances of all technicians

	Supervisor S1;		//Supervisor
	Refuel fueler1;

	//JACKS
	Jacks j1(1);
	Jacks j2(2);

	//NUT TECHS
	Nuts n1(1), n2(2), n3(3), n4(4);

	//REMOVAL TECHS
	Wheel_Removal r1(1), r2(2), r3(3), r4(4);

	//SECURING TECHS
	Wheel_Securing w1(1), w2(2), w3(3), w4(4);


	cout << "Creating all cars.....\n";
	car1.Resume();
	car2.Resume();
	car3.Resume();
	car4.Resume();
	car5.Resume();
	car6.Resume();
	car7.Resume();
	car8.Resume();
	car9.Resume();
	car10.Resume();

	cout << "Creating all technicians...\n";
	//Supervisor
	S1.Resume();
	//Fuel Tech
	fueler1.Resume();

	//Jacks
	j1.Resume();
	j2.Resume();

	//Nut techs
	n1.Resume();
	n2.Resume();
	n3.Resume();
	n4.Resume();
	//Wheel remover techs
	r1.Resume();
	r2.Resume();
	r3.Resume();
	r4.Resume();

	//Wheel securing techs
	w1.Resume();
	w2.Resume();
	w3.Resume();
	w4.Resume();

	//SLEEP(5000);
	//pitstop.Signal();		//Enter pitstop and signal supervisor to turn lights to red
	////Wait for pitstop to finish
	//finished.Wait();

	//cout << "Car is now out of the pitstop!!!\n";

	S1.WaitForThread();

	fueler1.WaitForThread();

	j1.WaitForThread();
	j2.WaitForThread();

	n1.WaitForThread();
	n2.WaitForThread();
	n3.WaitForThread();
	n4.WaitForThread();

	r1.WaitForThread();
	r2.WaitForThread();
	r3.WaitForThread();
	r4.WaitForThread();

	w1.WaitForThread();
	w2.WaitForThread();
	w3.WaitForThread();
	w4.WaitForThread();

	car1.WaitForThread();
	car2.WaitForThread();
	car3.WaitForThread();
	car4.WaitForThread();
	car5.WaitForThread();
	car6.WaitForThread();
	car7.WaitForThread();
	car8.WaitForThread();
	car9.WaitForThread();
	car10.WaitForThread();



	return 0;
}