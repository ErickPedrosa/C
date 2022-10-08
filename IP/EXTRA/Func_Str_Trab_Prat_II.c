#include <stdio.h>
#include <string.h>

#define SUCESSO 0



int main(int argc, char** argv) {

	char string1[20], string2[20], string3[20], string_buffer[20];
	int i;

	//OBS: MUDAR O LIMITE DA STRING;

	fgets(string1, 20, stdin);
	fgets(string2, 20, stdin);
	fgets(string3, 20, stdin);



	for (i = 0; string1[i] != '\0'; i++)
	{
		while (string1[i] == ' ')
		{
			for (int y = i; string1[y] != '\0'; y++)
			{
				string1[y] = string1[y + 1];
			}
		}
	}
	for (i = 0; string1[i] != '\0'; i++) {
		if (string1[i] <= 90 && string1[i] >= 65)
		{
			string1[i] += 32;
		}
	}
	
	if (strcmp(string1, string2) > 0)
	{
		memcpy(string_buffer, string2, 20);
		memcpy(string2, string1, 20);
		memcpy(string1, string_buffer, 20);
	}
	if (strcmp(string2, string3) > 0)
	{
		memcpy(string_buffer, string3, 20);
		memcpy(string3, string2, 20);
		memcpy(string2, string_buffer, 20);
	}
	if (strcmp(string1, string2) > 0)
	{
		memcpy(string_buffer, string2, 20);
		memcpy(string2, string1, 20);
		memcpy(string1, string_buffer, 20);
	}


	fputs(string1, stdout);
	fputs(string2, stdout);
	fputs(string3, stdout);

	return SUCESSO;
}