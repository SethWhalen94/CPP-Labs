#ifndef __Semaphores__
#define __Semaphores__
#include "..\rt.h"

CSemaphore light("Pit_entry_light", 0, 3);	//Pit entrance and exit light, Supervisor controlled, wait for fuel, and 2 jacks to lower car
//CSemaphore light2("Pit_exit_light", 0, 15);		//Pit exit light, Initially RED, Wait for all techs (except Supervisor) to be done
CSemaphore fuel("Fuel_car", 0, 1);			//Refuel Tech waits for 2 JACK tecks to start raising car

//====================
// Jacking technicians
//=====================
CSemaphore StartJacks("Start_Jacks", 0, 2);	//Supervisor signals Jacks
CSemaphore jackFup("Raise_Front", 0, 2);	//Raise front of car
CSemaphore jackBup("Raise_Back", 0, 2);		//Raise back
CSemaphore jackFdown("Lower_Front", 0, 2);	//Lower front of car
CSemaphore jackBdown("Lower_Back", 0, 2);		//Lower back

//====================
// Wheel technicians
//=====================
//				  BACK
//		Tire3 []--|	  |--[] Tire 4
//				  |   |
//			      |	  |
//		Tire2 []--|   |--[] Tire 1
//					FRONT
CSemaphore FrontWheels("Tires_Front", 0, 2);// Initally 0 since they haven't been changed yet
CSemaphore BackWheels("Tires_Back", 0, 2);// Initally 0 since they haven't been changed yet
//Nut techs
CSemaphore Nut1("Nut1", 0, 1);			//Nut technician waiting for Front jacked up
CSemaphore Nut2("Nut2", 0, 1);			//Nut technician waiting for Front jacked up
CSemaphore Nut3("Nut3", 0, 1);			//Nut technician waiting for Back be jacked up
CSemaphore Nut4("Nut4", 0, 1);			//Nut technician waiting for Back be jacked up
//Wheel removal
CSemaphore Off1("Off1", 0, 1);			//Wheel removal waiting until NUT tech is done
CSemaphore Off2("Off2", 0, 1);			//Wheel removal waiting until NUT tech is done
CSemaphore Off3("Off3", 0, 1);			//Wheel removal waiting until NUT tech is done
CSemaphore Off4("Off4", 0, 1);			//Wheel removal waiting until NUT tech is done
//Wheel securing
CSemaphore On1("On1", 0, 1);			//Wheel securing waits for REMOVAL tech to finish
CSemaphore On2("On2", 0, 1);			//Wheel securing waits for REMOVAL tech to finish
CSemaphore On3("On3", 0, 1);			//Wheel securing waits for REMOVAL tech to finish
CSemaphore On4("On4", 0, 1);			//Wheel securing waits for REMOVAL tech to finish

//Car semaphore when pitstop is needed
CSemaphore pitstop("Pit_Stop", 0, 10);			//Only allows 1 car in, but can have a lineup of 10 cars that need a pitstop
CSemaphore finished("Done_Pit_stop", 0, 1);		//Signal car that the pitstop is done
#endif // !__Semaphores__

