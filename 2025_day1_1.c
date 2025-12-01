#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() 
{
	char direction = 'R';
	int zerohits = 0;
	int finalcount = 50; // We start at position 50

	//2025_day1_1_input.txt
	FILE *file = fopen("2025_day1_1_input.txt", "r");
	if (file == NULL) {
		printf("Failed to open the file.\n");
		return 1;
	}

	char buffer[4096];
	while (fgets(buffer, sizeof(buffer), file) != NULL) {
		direction = buffer[0];
		int number = atoi(buffer+1);

		if (direction  == 'R') {	
			for(int i = 0; i<number; i++) {
				finalcount++;			
				if(finalcount > 99) {
					finalcount = 0;
				}
			}
		}
		else if (direction == 'L') {
			for(int i = number; i>0; i--) {
				finalcount--;
				if(finalcount < 0) {
					finalcount = 99;
				}
			}	
		}
		else {
			printf("Complete failure");
		}

		if(finalcount == 0) {
			zerohits+=1;
		}
	}

	printf("Amount of zerohits = %d\n", zerohits);
	
	fclose(file);
    return 0;
}
