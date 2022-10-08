#include <stdio.h>
#include <time.h>

#define SUCESSO 0



int main(int argc, char** argv) {

	time_t raw_time;
	time(&raw_time);
	
	struct tm* timeinfo;
	char buffer[80];
	
	timeinfo = localtime(&raw_time);

	strftime(buffer, 80, "Now it's %R:%S, Dia %j de %Y.", timeinfo);
	puts(buffer);

	

	time(&raw_time);
	fputs(ctime(&raw_time), stdout);
	

	return SUCESSO;
}