#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <vector>
#include<cstdlib>
#include <unistd.h> // For usleep

using namespace std;

int images [784]={
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0404, 0x1D9E, 0x1D9E, 0x3F3F, 0x3FC0, 0x4000, 0x3FC0, 0x3C3C, 0x1C9D, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0CCD, 0x3B3B, 0x3F7F, 0x3F7F, 0x3F7F, 0x36F7, 0x2767, 0x2767, 0x3737, 0x3F7F, 0x1E1E, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0E0E, 0x3F7F, 0x3E7E, 0x2C6C, 0x0ACB, 0x0687, 0x0000, 0x0000, 0x16D7, 0x3F7F, 0x3131, 0x01C2, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0384, 0x0F4F, 0x0E8F, 0x0000, 0x0000, 0x0000, 0x0000, 0x02C3, 0x2E2E, 0x3F7F, 0x2060, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0747, 0x25E6, 0x3F7F, 0x3E3E, 0x0A8B, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0F90, 0x3ABB, 0x3F7F, 0x3F3F, 0x27A8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x2020, 0x3C3C, 0x3F7F, 0x3939, 0x1B9C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0182, 0x1BDC, 0x3EBF, 0x3F7F, 0x37F8, 0x0A8B, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0505, 0x1697, 0x2B6B, 0x3F7F, 0x3F7F, 0x3F7F, 0x21A2, 0x1252, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x1919, 0x3636, 0x3F7F, 0x3F7F, 0x3F7F, 0x2EAF, 0x2E2E, 0x3C3C, 0x3D3D, 0x33B4, 0x2020, 0x0909, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x3575, 0x3CFD, 0x3373, 0x3171, 0x1111, 0x0081, 0x0000, 0x0E0E, 0x1111, 0x2767, 0x3A3A, 0x3737, 0x2060, 0x01C2, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x12D3, 0x1192, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0DCE, 0x3BFC, 0x3F7F, 0x20E1, 0x0182, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0D8E, 0x3DBE, 0x3F7F, 0x2121, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x2B6B, 0x3F7F, 0x3777, 0x0949, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0182, 0x37B8, 0x3F7F, 0x12D3, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x21A2, 0x3E7E, 0x3F7F, 0x12D3, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0707, 0x1454, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0081, 0x2060, 0x3EBF, 0x3F7F, 0x3333, 0x0404, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0747, 0x1BDC, 0x0A8B, 0x0A8B, 0x0141, 0x0303, 0x0A8B, 0x20E1, 0x2D6D, 0x3F7F, 0x3F7F, 0x2B2B, 0x0E4E, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x22E3, 0x3CFD, 0x3F7F, 0x2A2A, 0x2E2E, 0x3F7F, 0x3F7F, 0x3C7C, 0x2969, 0x1818, 0x0343, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0F0F, 0x1D1D, 0x3BFC, 0x3F7F, 0x3F7F, 0x28E9, 0x0C8D, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 
};


void write_bram(int images[784]);
void write_start(int start);
void read_bram();

int main ()
{	

	write_bram(images);
	cout<<"Sending data to BRAM..." << endl; 
	
	write_start(1);
	
	usleep(2000);
	
	read_bram();
				
	return 0;
}


void write_bram(int images[784])
{
    FILE *bram; 

    // Check if the file was opened successfully
    if (bram == NULL) {
        perror("Error opening file");
        return;
    }


    for (int i = 0; i < 784; i++)
    {
		bram = fopen ("/dev/xlnx,bram", "w");
        fprintf(bram, "%d, %d",i,images[i]);
		fclose(bram);

    }



}

void write_start(int start)
{
	FILE *deskew;
	
	deskew = fopen ("/dev/xlnx,deskew", "w");
	fprintf(deskew, "%d", start);
	fclose(deskew);
	
}

void read_bram()
{
	FILE *bram;

	int value[784];
	
    bram = fopen ("/dev/xlnx,bram", "r");
	
	for (int i = 0; i < 784; i++)
		fscanf(bram, "%d", &value[i]);
	
	fclose(bram);
	
	bram = fopen ("bram.txt", "w");
	
	for (int i = 0; i < 27; i++)
    {
		for(int j = 0; j < 29; j++)
			fprintf(bram, "0x%04x, ", value[i*29 + j]);
		
		fprintf(bram, "\n");
    }

	fclose(bram);
	
	

	
}



	
