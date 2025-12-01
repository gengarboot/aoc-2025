#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() 
{
	char direction = 'R';
	int hits = 0;
	int dialPos = 50; // We start at position 50 (0-99)

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
            for(int i = 0; i < number; ++i) {
                dialPos+=1;
                if(dialPos == 100) {
                    hits+=1;
                    dialPos = 0;
                }
            }
		}
		else if (direction == 'L') {
            for(int i = number; i > 0; --i) {
                dialPos-=1;
                if (dialPos == 0) {
                    hits+=1;
                }
                if(dialPos == -1) {
                    dialPos = 99;
                }
            }
		}
		else {
			printf("Complete failure");
		}
	}

	printf("Hits at 0 = %d\n", hits);
	
	fclose(file);
    return 0;
}
