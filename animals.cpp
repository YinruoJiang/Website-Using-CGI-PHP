/*
FILE: animals.exe
PROJECT : assignment - WDD - A03
PROGRAMMER : Yinruo Jiang
FIRST VERSION : 2021 - 10 - 09
SECOND VERSION : 2021 - 10 - 10
DESCRIPTION : This source mainly receive the username and animal choice from html, and display imageand text file content
*/
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <regex>


#pragma warning(disable : 4996)		// need to do this to be able to use getenv()
using std::string;

int main(void)
{
	char* data;			// notice that this variable (used to grab/point to the environment variable(s)) just needs to be a poitner
	string fName ;		// local variables to hold the values passed in through the environment variables
	string animalSelected;

	printf("Content-type:text/html\n\n");
	printf("<html><head><title> My CGI Zoo </title>\n"); // set title name
	printf("<style>\n");
	printf("body{\nbackground: lightyellow;\n}\n"); // set body background colour
	printf("</style>\n");
	printf("</head>");
	printf("<body>\n");
	printf("<h3>Pet Facts!</h3>\n");
	printf("<hr>");

	// get the information passed into the CGI program and scanf it out ...
	data = getenv("QUERY_STRING");
	string datastr(data);

	std::regex rgx("animal=([A-Za-z\+]+)\&fname1=([A-Za-z\+]+)"); //set the regex for the user input
	std::smatch matches;

	if (regex_search(datastr, matches, rgx)) {
		if (matches.size() != 3) {	
			printf("Invalid Input!");
			return 1;
		}
		fName = matches[2].str(); 
		animalSelected = matches[1].str();
	}
	else {
		printf("Invalid Input!");
		return 1;
	}
	std::replace(fName.begin(), fName.end(), '+', ' ');
	printf("<p>Hello, %s! You selected to learn more about the %s</p>\n", fName.c_str(), animalSelected.c_str());
	printf("<p>Look how cute they can be!\n</p>");
	printf("<hr>");

	printf("<div style=\"overflow: hidden;\">");
	printf("<img src='theZoo/%s.png' style='width:300px;height:auto;float:left;'>", animalSelected.c_str());
	FILE* fp = NULL;
	char record[80] = { 0 };
	string path = "theZoo/"+ animalSelected+ ".txt";

	fp = fopen(path.c_str(), "r");
	if (fp == NULL)
	{
		printf("Can't open TEXT file.\n");
		return -1;
	}

	printf("<div style=\"float:left;\">");
	while (fgets(record, sizeof record, fp) > 0)
	{
		printf("%s", record);
	}
	if (fclose(fp) != 0)
	{
		printf("Can't close the TEXT file.\n");
		return 1;
	}
	printf("</div>");
	printf("</div>");
	printf("<hr></body></html>");
	return 0;
}
