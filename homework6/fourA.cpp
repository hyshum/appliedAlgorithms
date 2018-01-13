//HOKYINSHUM

#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>

using namespace std;

void fourA()
{
	char c;
	int i = 0;
	int total = 0;
	int count = 0;
	bool check = false;

	ifstream input;
	input.open("BigData.txt"); // Open the datafile.

	while (!input.eof())
	{

		if(c != 'U') input.get(c); //If the character is not C, get a char.

		if (c == 'U')
		{
			while (i < 8 && !check) //escape when its closed by non-digit or 8 int.
                              //reset if there is ever an U.
			{
				input.get(c);
				if(isdigit(c))
				{
					total += c - 48; // get ASCII value.
					i++;
				}
				else if (c == 'U') // if there's U reset.
				{
					i = 0;
					total = 0;
				}
				else check = true; //time to move on...
			}// End of getting an item starting with U.
      //Checking item starting with U.
			if (i == 8 && total >= 31 && total <=68) // if its valid, check final step.
			{
				input.get(c); //FINAL STEP: NON-Digit end?

					if (!isdigit(c))
					{
						count++; //All the criterias are met!
					}

			}
			total = 0; //reset sum of 8 digits
			i = 0;
			check = false;
		}
	}//while not eof. looping.
	cout << count << endl;
}
int main()
{
  fourA();
}
