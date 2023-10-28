// DataFilePreparation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>


using namespace std;

void headerFormat(string& dataline, ofstream &outfile2); // formats the header 
string stationNameFormatter(string &part);



int main()
{

	string dataline = "", station = "", station_name = "", date = "";
	string space = " ";
	char letter;
	float mdpr = 0, dapr = 0, prcp = 0, snwd = 0, snow = 0, tmax = 0, tmin = 0, awnd = 0;
	int i = 0;

	ifstream infile, infile2;
	ofstream outfile, outfile2;

	infile.open("C:/Users/smith/source/repos/CS121/Data/AL_Weather_Station.txt");

	if (!infile)
	{
		cout << "Error opening the file." << endl;
		system("PAUSE");
		return 1;
	}
	cout << "Input file opened. " << endl;

	outfile.open("C:/Users/smith/source/repos/CS121/Data/Filtered_AL_Weather_Station.txt");

	if (!outfile)
	{
		cout << "Error opening the file." << endl;
		system("PAUSE");
		return 1;
	}
	cout << "Output file opened. " << endl;
	outfile << fixed;

	//cout << "Read the first line. Column Headers. " << endl;
	getline(infile, dataline);

	outfile << dataline << endl;

	//cout << "Read the second line (dashes) from the file. " << endl;
	getline(infile, dataline);

	outfile << dataline << endl;

	while (!infile.eof())
	{
		// Read the first line of data from the buffer.
		infile >> station;

		// Ignore the space after Station ID.
		infile.ignore(1);

		// Read the station name letter by letter
		for (i = 1; i <= 50; i++)
		{
			infile.get(letter);
			station_name = station_name + letter;
		}

		// Read the date as a string
		infile >> date;

		//Now it is easy to read the remaining data.
		infile >> mdpr >> dapr >> prcp >> snwd >> snow >> tmax >> tmin >> awnd;

		// Test for bad data in tmax and tmin
		if (tmax != -9999 && tmin != -9999 && prcp != -9999)
		{
			outfile << station << space
				<< station_name << space
				<< date << space
				<< left// All remaining fields are left justified
				<< setw(8) << setprecision(0) << mdpr << space
				<< setw(8) << setprecision(0) << dapr << space
				<< setw(8) << setprecision(2) << prcp << space
				<< setw(8) << setprecision(1) << snwd << space
				<< setw(8) << setprecision(0) << snow << space
				<< setw(8) << setprecision(0) << tmax << space
				<< setw(8) << setprecision(0) << tmin << space
				<< setw(8) << setprecision(0) << awnd << space
				<< endl;
		}
		station_name = ""; // Reset station_name for next record 
	}// End while loop
	cout << "\nFiltered data file created. " << endl;

	// Close the files

	infile.close();
	outfile.close();

	//---------------------------------------------------------------------------------------------------------------



	string dataline2 = "", station2 = "", station_name2 = "", date2 = "";
	char letter2;
	float mdpr2 = 0, dapr2 = 0, prcp2 = 0, snwd2 = 0, snow2 = 0, tmax2 = 0, tmin2 = 0, awnd2 = 0;

	infile2.open("C:/Users/smith/source/repos/CS121/Data/Filtered_AL_Weather_Station.txt");

	if (!infile2)
	{
		cout << "Error opening the file." << endl;
		system("PAUSE");
		return 1;
	}
	cout << "\nSecond input file opened." << endl;

	outfile2.open("C:/Users/smith/source/repos/CS121/Data/weather_station_five_column.txt");

	if (!outfile2)
	{
		cout << "Error opening the file." << endl;
		system("PAUSE");
		return 1;
	}
	cout << "Second output file opened." << endl << endl;
	cout << fixed;

	//cout << "Read the first line. Column Headers. " << endl;
	getline(infile2, dataline2);

	int position[6];
	string stations[6] = { "STATION", "MDPR", "DAPR", "SNWD", "SNOW", "AWND" };

	for (int i = 0; i < 6; i++) //erases header columns
	{

		position[i] = dataline2.find(stations[i]);

		dataline2.erase(position[i], 8);

	}

	headerFormat(dataline2, outfile2); // function that fomats the header of the new output file

	getline(infile2, dataline2); //cout << "Read the second line (dashes) from the file. " << endl;

	while (infile2 >> station2) {
		// Read the station name
		
		station_name2 = "";
		
		for (i = 1; i <= 51; i++) {
			infile2.get(letter);
			station_name2 = station_name2 + letter;
		}
		
		stationNameFormatter(station_name2);

		// Read the rest of the data
		infile2 >> date2 >> mdpr2 >> dapr2 >> prcp2 >> snwd2 >> snow2 >> tmax2 >> tmin2 >> awnd2;

		// Check for the end of the file
		if (infile2.eof()) {
			break; // Exit the loop when you reach the end of the file
		}

		// Format the date
		string formattedDate = date2.substr(4, 2) + " " + date2.substr(6, 2) + " " + date2.substr(0, 4);

		
		outfile2 << left << setw(50) << station_name2;
		outfile2 << left << setw(12) << formattedDate;

		outfile2 << fixed <<left << setw(8) << setprecision(2) << prcp2
		 << left << setw(8) << setprecision(2) << tmax2
		 << left << setw(8) << setprecision(2) << tmin2
		 << endl;

		station_name2 = "";
	}

	cout << "Filtered data file created. ";

		infile2.close();
		outfile2.close();

		cout << "\n\n";
		system("pause");
		return 0;

}

void headerFormat(string& dataline2, ofstream &outfile2) // formats the header 
{
	istringstream dataParser(dataline2);
	string stationPart, datePart;
	string prcpPart, tmaxPart, tminPart;

	dataParser >> stationPart >> datePart >> prcpPart >> tmaxPart >> tminPart;

	outfile2 << left << setw(50) << stationPart << setw(12) << datePart << setw(8)
		<< prcpPart << setw(8) << tmaxPart << setw(8) << tminPart << endl;

}

string stationNameFormatter(string &part)
{
	while (!part.empty() && isspace(*part.begin()))
		part.erase(part.begin());

	return part;
}

