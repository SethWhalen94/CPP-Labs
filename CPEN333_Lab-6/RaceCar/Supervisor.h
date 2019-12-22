#ifndef __Supervisor__
#define __Supervisor__
#include "Semaphores.h"

//CSemaphore light("Pit_entry_light", 15, 15);	//Pit entrance light, GREEN when all technicians are ready, Initiall Green
////CSemaphore light2("Pit_exit_light", 1, 1);		//Pit exit light, Initially RED, Wait for all techs (except Supervisor) to be done
//
//CSemaphore fuel("Fuel_car", 0, 1);
//CSemaphore StartJacks("Start_Jacks", 0, 2);
class Supervisor : public ActiveClass
{

private:
	int main(void)
	{
		cout << "Supervisor Is awake...\n";
		SLEEP(2000);
		//cout << "The Pit Entrance and Exit Lights are GREEN..\n";
		while (1)
		{
			//MOVE_CURSOR(10, 20);
			//for (int i = 0; i < 15; i++)
			//	light.Wait(); //#1

			cout << "The Pit Entrance and Exit Lights are GREEN..\n";
			cout << "Waiting for car to enter....\n";
			pitstop.Wait();		//Wait for car to need pitstop
			//MOVE_CURSOR(10, 20);
			cout << "The Pit Entrance and Exit Lights are RED..\n";
			//Signal refuel and Jack techs
			fuel.Signal();		//Start fueling
			StartJacks.Signal();
			StartJacks.Signal();	//Signal jacks to start

			//Now wait for all technicians to finish
			light.Wait();		//Wait for Fuel
			light.Wait();		//Wait for jack #1 to lower
			light.Wait();		//wait for jack #2 to lower

			finished.Signal();		//Signal car that the pitstop is done
		}

		return 0;
	}
public:

	void Enter_Light()
	{
		cout << "The Pit Entrance light is RED..\n";
		cout << "The Pit Exit light is RED..\n";
		light.Wait(); //#1
		light.Wait(); //#2
		light.Wait(); //#3
		light.Wait(); //#4
		light.Wait(); //#5
		light.Wait(); //#6
		light.Wait(); //#7
		light.Wait(); //#8
		light.Wait(); //#9
		light.Wait(); //#10
		light.Wait(); //#11
		light.Wait(); //#12
		light.Wait(); //#13
		light.Wait(); //#14
		light.Wait(); //#15
		//light2.Wait();	//Exit light is red

		//Turn Green light on
		cout << "The Pit Entrance Light is Green..\n";
		cout << "The pit Exit Light is Green...\n";
		//Turn exit light to RED
		
		//Wait for technicians


	}

};


#endif // !__Supervisor__

