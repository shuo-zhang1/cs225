#include <iostream>
#include <fstream>
#include <string>
#include "Point.h"

int main() {
	/*
	Basic Algorithm
	Read all points (n points) into an array
	for each input point pi = (xi, yi)
	for each other point pj = (xj, yj)
	compute distance between pi and pj
	if ( distance < minimum distance )
	minimum distance = distance
	keep track of the points that generated this new min
	if ( distance > maximum distance )
	maximum distance = distance
	keep track of the points that generated this new min
	*/

	// declare an array of Point objects
	const int MAX_NUM_POINTS = 1000;
	Point points[MAX_NUM_POINTS];

	cout << "\n******* Minimum and Maximum Distances between Cartesian Plane Points  *******\n" << endl;

	//Get File Name
	string fileName;  // name of file


	//change to local string pathName = "H:\\Visual Studio 2015\\Projects\\CPPDataFiles\\";

	cout << "Enter file name: "; //get file name from user
	cin >> fileName;

	//Try to open file
	ifstream infile;   // Input file stream; used to read file named fileName

	infile.open(pathName + fileName);

	if (infile.fail()) {
		cout << "Cannot open file " << fileName
			<< " Aborting." << endl;
		system("pause");
		return 1;
	}

	//Read points from file in the array
	cout << "\nReading in numbers." << endl;
	int numOfPoints = 0;
	while (infile >> ws && !infile.eof() && numOfPoints <= MAX_NUM_POINTS)
	{
		infile >> points[numOfPoints]; // uses overloaded >> operator for reading points numOfPoints++;
		numOfPoints++;
	}
	//done reading so close file
	infile.close();
	//Output array contents
	cout << "Number of points read: " << numOfPoints << endl;
	cout << "Points read.." << endl;
	for (int i = 0; i < numOfPoints; i++) {
		cout << Point(points[i]) << endl;
	}

	//Compute and display min/max Cartesian distances
	double minDistance = 0;
	double maxDistance = 0;
	double distance;
	Point min1;
	Point max1;
	Point min2;
	Point max2;

	if (numOfPoints > 1) {
		minDistance = 2;
		for (int i = 0; i < numOfPoints; i++) {
			for (int j = i + 1; j < numOfPoints; j++) {
				if (points[i] != points[j]) {
					distance = points[i].distance(points[j]);
					if (distance < minDistance) {
						minDistance = distance;
						min1 = Point(points[i]);
						min2 = Point(points[j]);
					}
					if (distance > maxDistance) {
						maxDistance = distance;
						max1 = Point(points[i]);
						max2 = Point(points[j]);
					}
				}
			}
		}
	}
	cout << "\n\nMinimum distance = " << minDistance << " is between " << min1 << " and " << min2;
	cout << "\nMaximum distance = " << maxDistance << " is between " << max1 << " and " << max2;
	cout << "\n\n";
	system("pause");
	return 0;
}
