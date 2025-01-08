#include <stdio.h>

#define HEIGHT 10
#define WIDTH 10

void printArray(char arr[HEIGHT][WIDTH]);

int main() 
{
	// temporary prints
	printf("height: %d \n", HEIGHT);
	printf("width: %d \n", WIDTH);
	printf("\n\n");

	// define array
	char arr[HEIGHT][WIDTH];
	
	// Initialize array
	for (int i = 0; i < HEIGHT; i++) {
		for (int k = 0; k < WIDTH; k++) {
			arr[i][k] = '0';
		}
	}

	printArray(arr);

	return 0;
}

// helper function to print array
void printArray(char arr[HEIGHT][WIDTH])
{
	for (int i = 0; i < HEIGHT; i++) {
		for (int k = 0; k < WIDTH; k++) {
			printf("%c ", arr[i][k]);
		}
		printf("\n");
	}	
}


